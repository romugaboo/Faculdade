from timeit import default_timer as timer
import argparse
import matplotlib.pyplot as plt
from scipy.signal import savgol_filter
from tql_mountain import QLearningAgentTabular
from mountaincar_environment import MountainCarEnvironment
import gymnasium as gym

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--num_episodes", type=int, default=6000, help="Number of episodes")
    parser.add_argument("--env_name", type=str, default="MountainCar-v0", help="Environment name")
    parser.add_argument("--decay_rate", type=float, default=0.0001, help="Decay rate")
    parser.add_argument("--learning_rate", type=float, default=0.7, help="Learning rate")
    parser.add_argument("--gamma", type=float, default=0.618, help="Gamma")
    args = parser.parse_args()

    env = MountainCarEnvironment(gym.make(args.env_name).env)

    agent = QLearningAgentTabular(
        env=env,
        decay_rate=args.decay_rate,
        learning_rate=args.learning_rate,
        gamma=args.gamma
    )

    rewards = agent.train(args.num_episodes)
    agent.save(f"{args.env_name}-tql-agent.pkl")
    
    window_length = min(1001, len(rewards) - 1) 
    
    if window_length % 2 == 0:
        window_length -= 1
    
    smoothed_rewards = savgol_filter(rewards, window_length, 2)

    plt.plot(savgol_filter(rewards, window_length, 2))
    plt.title(f"Curva de aprendizado suavizada ({args.env_name})")
    plt.xlabel('Episódio')
    plt.ylabel('Recompensa total')
    plt.savefig(f"{args.env_name}-tql-learning_curve.png")
    plt.close()

    plt.plot(agent.epsilons_)
    plt.title(f"Decaimento do valor de $\epsilon$ ({args.env_name})")
    plt.xlabel('Episódio')
    plt.ylabel('$\epsilon$')
    plt.savefig(f"{args.env_name}-tql-epsilons.png")
    plt.close()
