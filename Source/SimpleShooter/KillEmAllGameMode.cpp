// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "GameFramework/Controller.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	
	UE_LOG(LogTemp, Warning, TEXT("A pawn was killed"));

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false);	//player lose and end game
	}

	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead())
		{
			return;
		}
	}
	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))	//iterate over all actors
	{
		bool bIsWinner=Controller->IsPlayerController()==bIsPlayerWinner; //check if it's player and check if who is winner ->if both of them are true return true
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);	
	}
}
