#include "Gameplay.h"

Gameplay::Gameplay()
	:
	gameMode(true),
	deployment(true),
	countHitsPlayer(0),
	countHitsOpponent(0),
	winCondition(20)
{}

void Gameplay::startGame()
{
	gameMode = menu.selectGameMode();

	rend.hideCursor(false);

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

	rend.hideCursor(false);

	if (gameMode)
	{
		while (true)
		{
			menu.counterPlayerHits(countHitsPlayer, winCondition);
			menu.counterOpponetsHits(countHitsOpponent, winCondition);

			if (isPlayer)
			{
				player.outputPlayerBoard();
				bptr = &player;
				isPlayer = player.shootingPlayer(*(bptr), countHitsPlayer) ? true : false;
				menu.declareWinnerPlayer(countHitsPlayer, winCondition);
			}
			else
			{
				bptr = &player;
				isPlayer = opponent.shootingOpponentRandomly(*(bptr), countHitsOpponent) ? false : true;
				menu.declareWinnerOpponent(countHitsOpponent, winCondition);
			}
		}

		return;
	}

	else
	{
		while (countHitsPlayer < winCondition || countHitsOpponent < winCondition)
		{
			Sleep(500);
			menu.counterPlayerHits(countHitsPlayer, winCondition);
			menu.counterOpponetsHits(countHitsOpponent, winCondition);

			if (isDemo)
			{
				demo.outputPlayerBoard();
				opponent.outputEnemyBoard();
				bptr = &opponent;
				isDemo = demo.shootingOpponentRandomly(*(bptr), countHitsPlayer) ? true : false;
				menu.declareWinnerPlayer(countHitsPlayer, winCondition);
			}
			else
			{
				bptr = &demo;
				isDemo = opponent.shootingOpponentRandomly(*(bptr), countHitsOpponent) ? false : true;
				menu.declareWinnerOpponent(countHitsOpponent, winCondition);
			}
		}

		return;
	}
}