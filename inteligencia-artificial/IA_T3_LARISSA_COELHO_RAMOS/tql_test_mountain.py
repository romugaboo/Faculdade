import argparse
from tql_mountain import QLearningAgentTabular  # Certifique-se de que o import está correto para o arquivo onde a classe está definida

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--env_name", type=str, default="MountainCar-v0", help="Environment name")
    parser.add_argument("--num_episodes", type=int, default=1000, help="Number of episodes")
    args = parser.parse_args()
    assert args.num_episodes > 0

    # Carrega o agente treinado
    agent = QLearningAgentTabular.load_agent(args.env_name + "-tql-agent.pkl")

    total_actions, total_rewards = 0, 0

    for episode in range(args.num_episodes):
        state, _ = agent.env.reset()  # Reinicia o ambiente
        num_actions = 0
        episode_reward = 0

        terminated = False
        truncated = False

        while not (terminated or truncated):
            # Converte o estado contínuo para o estado discretizado
            state_p, state_v = agent.get_state_id(state)

            # Escolhe a ação com base nos índices discretizados e sem exploração
            action = agent.choose_action((state_p, state_v), is_in_exploration_mode=False)

            # Executa a ação no ambiente e obtém o próximo estado
            state, reward, terminated, truncated, _ = agent.env.step(action)

            num_actions += 1
            episode_reward += reward

        total_actions += num_actions
        total_rewards += episode_reward

    print("***Results***********************")
    print(f"Average episode length: {total_actions / args.num_episodes}")
    print(f"Average rewards: {total_rewards / args.num_episodes}")
    print("**********************************")
