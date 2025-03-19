import numpy as np

class MountainCarEnvironment:
    def __init__(self, env):
        self.env = env
        self.pos_space = np.linspace(self.env.observation_space.low[0], self.env.observation_space.high[0], 10)
        self.vel_space = np.linspace(self.env.observation_space.low[1], self.env.observation_space.high[1], 10)

    def get_num_states(self):
        return len(self.pos_space) * len(self.vel_space)

    def get_num_actions(self):
        return self.env.action_space.n

    def reset(self):
        return self.env.reset()

    def step(self, action):
        return self.env.step(action)

    def get_state_id(self, state):
        state_p = np.digitize(state[0], self.pos_space)
        state_v = np.digitize(state[1], self.vel_space)
        return state_p * len(self.vel_space) + state_v
    
    @property
    def observation_space(self):
        return self.env.observation_space

    @property
    def action_space(self):
        return self.env.action_space
