//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "conquerPortMiniGame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#include <algorithm>
TconquerPortMiniGameForm *conquerPortMiniGameForm;
void show (TImage *i) {  // function:
	i->Visible=true;;
}
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
	rightBall->Position->X -= 20;
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
				if (bottlesLeft.empty())
				{
                    winnerName->Text = leftPlayerName->Text;
					handleEndOfTheMiniGame();
					bottlesLeft.push_back(leftGamerBottle3);
					bottlesLeft.push_back(leftGamerBottle2);
					bottlesLeft.push_back(leftGamerBottle1);
				}
            }
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TconquerPortMiniGameForm::leftBallTimerTimer(TObject *Sender) // Defender
{
	leftBall->Position->X +=20;
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
				if (bottlesRight.empty())
				{
                    winnerName->Text = rightPlayerName->Text;
					handleEndOfTheMiniGame();
					bottlesRight.push_back(rightGamerBottle1);
					bottlesRight.push_back(rightGamerBottle2);
					bottlesRight.push_back(rightGamerBottle3);
				}
			}
		}
	}

}

void TconquerPortMiniGameForm::runConquerPortMiniGame(Player *DefendingPlayer, Player *AttackingPlayer, TportsCardFrame *cardOfRelatedPort)
{
	this->cardOfRelatedPort =  cardOfRelatedPort;
	rightBall->Visible = true;
    leftBall->Visible = true;
	leftPlayerName->Text =  DefendingPlayer->getName();
	rightPlayerName->Text = AttackingPlayer->getName();
	this->AttackingPlayer = AttackingPlayer;
	this->DefendingPlayer = DefendingPlayer;
	shipLeft->Visible = true;
	shipRight->Visible = true;
	for_each(bottlesRight.begin(), bottlesRight.end(), show);
	for_each(bottlesLeft.begin(), bottlesLeft.end(), show);
	Visible = true;
}

//---------------------------------------------------------------------------

void __fastcall TconquerPortMiniGameForm::closeButtonImageClick(TObject *Sender)
{
	winLabelImage->Visible = false;
	closeButtonImage->Visible = false;
	winnerName->Visible = false;
	winnerInfoBackground->Visible = false;
	Visible = false;
	cardOfRelatedPort->Visible = false;

}
void TconquerPortMiniGameForm::handleEndOfTheMiniGame()
{
	winLabelImage->Visible = true;
	closeButtonImage->Visible = true;
	winnerName->Visible = true;
	winnerInfoBackground->Visible = true;
	shipLeft->Visible = false;
	shipRight->Visible = false;
	rightBall->Visible = false;
    leftBall->Visible = false;
}
//---------------------------------------------------------------------------

