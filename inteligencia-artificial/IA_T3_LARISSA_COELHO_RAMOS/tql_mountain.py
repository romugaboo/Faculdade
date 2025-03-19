from timeit import default_timer as timer
import numpy as np
import pickle

class QLearningAgentTabular:

    def __init__(self, env, decay_rate, learning_rate, gamma):
        self.env = env
        # Discretização de posição e velocidade em 20 segmentos cada
        self.pos_space = np.linspace(self.env.observation_space.low[0], self.env.observation_space.high[0], 20)
        self.vel_space = np.linspace(self.env.observation_space.low[1], self.env.observation_space.high[1], 20)
        
        # Inicializa a tabela Q com base nas dimensões discretizadas de posição, velocidade e ações possíveis
        self.q_table = np.zeros((len(self.pos_space), len(self.vel_space), self.env.action_space.n))
        self.epsilon = 1.0
        self.max_epsilon = 1.0
        self.min_epsilon = 0.01
        self.decay_rate = decay_rate = 0.001
        self.learning_rate = learning_rate = 0.9
        self.gamma = gamma
        self.epsilons_ = []

    def get_state_id(self, state):
        """Converte o estado contínuo para um índice discretizado da Q-table."""
        state_p = np.digitize(state[0], self.pos_space) - 1  # -1 para ajustar ao índice da tabela Q
        state_v = np.digitize(state[1], self.vel_space) - 1
        return state_p, state_v

    def choose_action(self, state, is_in_exploration_mode=True):
        state_p, state_v = self.get_state_id(state)
        exploration_tradeoff = np.random.uniform(0, 1)

        if is_in_exploration_mode and exploration_tradeoff < self.epsilon:
            # Exploração: escolha de ação aleatória
            action = self.env.action_space.sample()
        else:
            # Exploração: escolha da ação com maior valor Q
            action = np.argmax(self.q_table[state_p, state_v, :])

        return action

    def update(self, state, action, reward, next_state):
        """Atualiza a Q-table com base na fórmula de Q-learning."""
        state_p, state_v = self.get_state_id(state)
        next_state_p, next_state_v = self.get_state_id(next_state)

        # Fórmula de atualização da Q-table
        self.q_table[state_p, state_v, action] += self.learning_rate * (
            reward + self.gamma * np.max(self.q_table[next_state_p, next_state_v, :]) - self.q_table[state_p, state_v, action]
        )

    def train(self, num_episodes):
        rewards_per_episode = []
        start_time = timer()

        for episode in range(num_episodes):
            terminated = False
            state, _ = self.env.reset()  # Reinicia o ambiente

            rewards_in_episode = []
            total_penalties = 0

            while not terminated:
                action = self.choose_action(state)
                new_state, reward, terminated, _, _ = self.env.step(action)

                if reward < 0:
                    total_penalties += reward

                self.update(state, action, reward, new_state)

                if terminated:
                    # Decaimento de epsilon para reduzir exploração ao longo do tempo
                    self.epsilon = self.min_epsilon + (self.max_epsilon - self.min_epsilon) * \
                        np.exp(-self.decay_rate * episode)
                    self.epsilons_.append(self.epsilon)

                state = new_state
                rewards_in_episode.append(reward)

            sum_rewards = np.sum(rewards_in_episode)
            rewards_per_episode.append(sum_rewards)

            if episode % 100 == 0:
                end_time = timer()
                execution_time = end_time - start_time
                print(f"Stats for episode {episode}/{num_episodes}:")
                print(f"\tNumber of actions: {len(rewards_in_episode)}")
                print(f"\tTotal reward: {sum_rewards:.2f}")
                print(f"\tExecution time: {execution_time:.2f}s")
                print(f"\tTotal penalties: {total_penalties}")
                start_time = end_time

        return rewards_per_episode

    def save(self, filename):
        with open(filename, 'wb') as file:
            pickle.dump(self, file)

    @staticmethod
    def load_agent(filename):
        with open(filename, 'rb') as file:
            return pickle.load(file)
