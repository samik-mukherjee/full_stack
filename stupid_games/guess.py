import random


random_num = random.randint(1,50)
player_guess = input("type your guess: ")

while (player_guess != random_num):

	if random_num == int(player_guess):
		print("your guess was right on !")
		break

	elif random_num > int(player_guess):
		print("guess higher")
		player_guess =input("guess again: ")

	elif random_num < int(player_guess):
		print("guess less")
		player_guess =input("guess again: ")
