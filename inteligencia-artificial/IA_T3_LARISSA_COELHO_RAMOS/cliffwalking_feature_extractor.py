import numpy as np
from feature_extractor import FeatureExtractor

special_locations_dict = {0: (0,0), 1: (0,4), 2: (4,0), 3: (4,3)}

class Actions:
  '''
    Actions
      0 : mover para baixo
      1 : mover para cima
      2 : mover para a direita
      3 : mover para a esquerda
  '''
  DOWN = 0
  UP = 1
  RIGHT = 2
  LEFT = 3

class TaxiFeatureExtractor(FeatureExtractor):
  __actions_one_hot_encoding = {
    Actions.DOWN:   np.array([1,0,0,0,0,0]), 
    Actions.UP:     np.array([0,1,0,0,0,0]), 
    Actions.RIGHT:  np.array([0,0,1,0,0,0]), 
    Actions.LEFT:   np.array([0,0,0,1,0,0])
  }

  def __init__(self, env):
    '''
    Initializes the TaxiFeatureExtractor object. 
    It adds feature extraction methods to the features_list attribute.
    '''
    self.env = env
    self.features_list = []
    self.features_list.append(self.f0)


  def get_num_features(self):
    '''
    Returns the number of features extracted by the feature extractor.
    '''
    return len(self.features_list) + self.get_num_actions()

  def get_num_actions(self):
    '''
    Returns the number of actions available in the environment.
    '''
    return len(self.get_actions())

  def get_action_one_hot_encoded(self, action):
    '''
    Returns the one-hot encoded representation of an action.
    '''
    return self.__actions_one_hot_encoding[action]

  def is_terminal_state(self, state):
    assert type(state) == int
    return state in [0, 85, 410, 475]
  
  def get_actions(self):
    '''
    Returns a list of available actions in the environment.
    '''
    return [Actions.DOWN, Actions.UP, Actions.RIGHT, Actions.LEFT, Actions.PICK, Actions.DROP]
  
  def get_features(self, state, action):
    '''
    Takes a state and an action as input and returns the feature vector for that state-action pair. 
    It calls the feature extraction methods and constructs the feature vector.
    '''
    # print("feature_vector.shape")

    feature_vector = np.zeros(len(self.features_list))
    # print(feature_vector.shape)

    for index, feature in enumerate(self.features_list):
      feature_vector[index] = feature(state, action)

    # print(feature_vector.shape)
    # constant feature corresponding to the bias term
    # feature_vector[0] = 1.0

    action_vector = self.get_action_one_hot_encoded(action)
    feature_vector = np.concatenate([feature_vector, action_vector])

    # print(feature_vector.shape)

    return feature_vector

  # def get_features(self, state, action):
  #     feature_values = []
  #     feature_values += [self.f0(state, action)]
  #     for a in self.get_actions():
  #         if a == action and (state not in self.get_terminal_states()):
  #             feature_values += [self.f1(state, action)]
  #             feature_values += [self.f2(state, action)]
  #             feature_values += [self.f3(state, action)]
  #             feature_values += [self.f4(state, action)]
  #             feature_values += [self.f5(state, action)]
  #             feature_values += [self.f6(state, action)]
  #             feature_values += [self.f7(state, action)]
  #         else:
  #             for _ in range(0, len(self.features_list)):
  #                 feature_values += [0.0]

  #     feature_vector = np.zeros(len(feature_values))
  #     for index, feature_value in enumerate(feature_values):
  #       feature_vector[index] = feature_value
      
  #     # print(f"feature_vector.shape = {feature_vector.shape}")
  #     return feature_vector

    
  def f0(self, state, action):
    '''
    This is just the bias term.
    '''
    return 1.0

  def f1(self, state, action):
    '''
    This feature computes the reciprocal distance from the taxi to the passenger
    '''