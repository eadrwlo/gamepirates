//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "conquerPortMiniGame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TconquerPortMiniGameForm *conquerPortMiniGameForm;
//---------------------------------------------------------------------------
__fastcall TconquerPortMiniGameForm::TconquerPortMiniGameForm(TComponent* Owner)
	: TForm(Owner)
{
	leftBall->Position->Y = shipLeft->Position->Y + 80;
	leftBall->Position->X = shipLeft->Position->X + 70;
	rightBall->Position->Y = shipRight->Position->Y + 60;
	rightBall->Position->X = shipRight->Position->X + 5;

	bottlesLeft.push_back(leftGamerBottle3);
	bottlesLeft.push_back(leftGamerBottle2);
	bottlesLeft.push_back(leftGamerBottle1);

	bottlesRight.push_back(rightGamerBottle1);
	bottlesRight.push_back(rightGamerBottle2);
	bottlesRight.push_back(rightGamerBottle3);
}
//---------------------------------------------------------------------------
void __fastcall TconquerPortMiniGameForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(bottlesLeft.empty() || bottlesRight.empty())
	{
        handleEndOfTheMiniGame();
	}

	switch( Key )
	{
	case VK_F1:
		shipLeft->Position->Y -= 15;
		if (!leftBallTimer->Enabled)
		{
			leftBall->Position->Y -=15;
        }
		break;
	case VK_CONTROL:
		shipLeft->Position->Y += 15;
		if (!leftBallTimer->Enabled)
		{
			leftBall->Position->Y +=15;
		}
		break;
	case VK_UP:
		shipRight->Position->Y -= 15;
		if (!rightBallTimer->Enabled)
		{
			rightBall->Position->Y -=15;
        }
		break;
	case VK_DOWN:
		shipRight->Position->Y += 15;
		if (!rightBallTimer->Enabled)
		{
			rightBall->Position->Y +=15;
        }
		break;
	case VK_SHIFT:
		leftBallTimer->Enabled = true;
		break;
	case VK_BACK:
		rightBallTimer->Enabled = true;
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TconquerPortMiniGameForm::rightBallTimerTimer(TObject *Sender)
{
	rightBall->Position->X -=10;
	if (rightBall->Position->X < shipLeft->Position->X + 10)
	{
		rightBallTimer->Enabled = false;
		rightBall->Position->Y = shipRight->Position->Y + 70;
		rightBall->Position->X = shipRight->Position->X + 5;
		if (rightBall->Position->Y > shipLeft->Position->Y &&
		rightBall->Position->Y < shipLeft->Position->Y +113)
		{
			if (!bottlesLeft.empty())
			{
				bottlesLeft.at(0)->Visible = false;
				bottlesLeft.erase(bottlesLeft.begin());
			}
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TconquerPortMiniGameForm::leftBallTimerTimer(TObject *Sender)
{
	leftBall->Position->X +=10;
	if (leftBall->Position->X > shipRight->Position->X + 10)
	{
		leftBallTimer->Enabled = false;
		leftBall->Position->Y = shipLeft->Position->Y + 80;
		leftBall->Position->X = shipLeft->Position->X + 70;
		if (leftBall->Position->Y > shipRight->Position->Y &&
		leftBall->Position->Y < shipRight->Position->Y +113)
		{
			if (!bottlesRight.empty())
			{
                bottlesRight.at(0)->Visible = false;
				bottlesRight.erase(bottlesRight.begin());
			}
		}
	}

}

void TconquerPortMiniGameForm::runConquerPortMiniGame(Player *DefendingPlayer, Player *AttackingPlayer)
{
	Visible = true;
	leftPlayerName->Text =  DefendingPlayer->getName();
	rightPlayerName->Text = AttackingPlayer->getName();
	this->AttackingPlayer = AttackingPlayer;
	this->DefendingPlayer = DefendingPlayer;
}

//---------------------------------------------------------------------------

void __fastcall TconquerPortMiniGameForm::closeButtonImageClick(TObject *Sender)
{
	winLabelImage->Visible = false;
	closeButtonImage->Visible = false;
	winnerName->Visible = false;
	winnerInfoBackground->Visible = false;
}
void TconquerPortMiniGameForm::handleEndOfTheMiniGame()
{
	if(bottlesLeft.empty()) // defender won
	{
		winnerName->Text = leftPlayerName->Text;
	}
	else if (bottlesLeft.empty())   // attacker won
	{
		winnerName->Text = rightPlayerName->Text;
    }
	winLabelImage->Visible = true;
	closeButtonImage->Visible = true;
	winnerName->Visible = true;
	winnerInfoBackground->Visible = true;
}
//---------------------------------------------------------------------------

