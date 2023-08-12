#include "Gameplay.h"

Gameplay::Gameplay()
	:
	gameMode(true),
	deployment(true)
{}

void Gameplay::startGame()
{
	gameMode = menu.selectGameMode();

	if (gameMode)
	{
		deployment = menu.selectDeploymentMethod();

		if (deployment)
		{
			system("cls");

			player.outputEnemyBoard();
			player.deploymentManualyRevealBoard(player);

			opponent.deploymentAutoHiddenBoard(opponent);
		}
		else
		{
			system("cls");

			player.outputEnemyBoard();
			player.deploymentAutoRevealBoard(player);

			opponent.deploymentAutoHiddenBoard(opponent);
		}
	}
	else
	{
		system("cls");

		player.outputEnemyBoard();
		demo.deploymentAutoRevealBoard(demo);

		player.outputEnemyBoard();
		opponent.deploymentAutoRevealBoard(opponent);
	}
}

void Gameplay::playGame()
{
	Board* bptr;

	bool isPlayer = true;
	bool isDemo = true;

	startGame();

	if (gameMode)
	{
		while (true)
		{
			if (isPlayer)
			{
				player.outputPlayerBoard();
				bptr = &opponent;
				player.shootingPlayer(*(bptr));
				isPlayer = false;
			}
			else
			{
				bptr = &player;
				opponent.shootingOpponentRandomly(*(bptr));
				isPlayer = true;
			}
		}
	}
	else
	{
		while (true)
		{
			Sleep(500);

			if (isDemo)
			{
				demo.outputPlayerBoard();
				opponent.outputEnemyBoard();
				bptr = &opponent;
				demo.shootingOpponentRandomly(*(bptr));
				isDemo = false;
			}
			else
			{
				bptr = &demo;
				opponent.shootingOpponentRandomly(*(bptr));
				isDemo = true;
			}
		}
	}
}