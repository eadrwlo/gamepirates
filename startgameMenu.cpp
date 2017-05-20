//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "startgameMenu.h"
#include "playerMenu.h"
#include "mainMenu.h"
#include "frameMap.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TstartgameMenu_frame *startgameMenu_frame;
//---------------------------------------------------------------------------
__fastcall TstartgameMenu_frame::TstartgameMenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
	number->ImageIndex = 0;
	player_frame3->Visible = false;
	player_frame4->Visible = false;
	playerList.push_back(player_frame1);
	playerList.push_back(player_frame2);
	playerList.push_back(player_frame3);
	playerList.push_back(player_frame4);
	player_frame1->playerAvatar->ImageIndex = 0;
    player_frame2->playerAvatar->ImageIndex = 1;
    it = playerList.begin() + 2;
}
//---------------------------------------------------------------------------


void __fastcall TstartgameMenu_frame::startgame_buttonClick(TObject *Sender)
{
	frame1Map->numberOfPlayers = number->ImageIndex + 2;
	for(int player = 0; player < frame1Map->numberOfPlayers; player++)
	{
		frame1Map->playersWhoAreStillInGame.push_back(true);
	}
	frame1Map->drawnNumber = 1;
	frame1Map->fillFieldsVectorWithFields();
	frame1Map->iterator = 0;
    fillPlayersVectorWithStartingSettings(frame1Map->numberOfPlayers);
	frame1Map->Visible = Visible;
	startgameMenu_frame->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TstartgameMenu_frame::goBack_buttonClick(TObject *Sender)
{
	startgameMenu_frame->Visible = false;

	mainMenu_frame->Visible = true;
}
//---------------------------------------------------------------------------

void TstartgameMenu_frame::fillPlayersVectorWithStartingSettings(int numberOfPlayers)
{
	switch (numberOfPlayers)
	{
		case 2 :
			frame1Map->players.push_back(new Player(player_frame1->playerNameInput->Text, 200, frame1Map->player1, frame1Map->moveInXAxisPlayer1,frame1Map->moveInYAxisPlayer1, frame1Map->fieldsVector[0]));
			frame1Map->players.push_back(new Player(player_frame2->playerNameInput->Text, 200, frame1Map->player2, frame1Map->moveInXAxisPlayer2,frame1Map->moveInYAxisPlayer2, frame1Map->fieldsVector[0]));
			frame1Map->player3->Visible = false;
			frame1Map->player4->Visible = false;
		case 3:
			frame1Map->players.push_back(new Player(player_frame1->playerNameInput->Text, 200, frame1Map->player1, frame1Map->moveInXAxisPlayer1,frame1Map->moveInYAxisPlayer1, frame1Map->fieldsVector[0]));
			frame1Map->players.push_back(new Player(player_frame2->playerNameInput->Text, 200, frame1Map->player2, frame1Map->moveInXAxisPlayer2,frame1Map->moveInYAxisPlayer2, frame1Map->fieldsVector[0]));
			frame1Map->players.push_back(new Player(player_frame3->playerNameInput->Text, 200, frame1Map->player3, frame1Map->moveInXAxisPlayer3,frame1Map->moveInYAxisPlayer3, frame1Map->fieldsVector[0]));
            frame1Map->player4->Visible = false;
		case 4:
			frame1Map->players.push_back(new Player(player_frame1->playerNameInput->Text, 200, frame1Map->player1, frame1Map->moveInXAxisPlayer1,frame1Map->moveInYAxisPlayer1, frame1Map->fieldsVector[0]));
			frame1Map->players.push_back(new Player(player_frame2->playerNameInput->Text, 200, frame1Map->player2, frame1Map->moveInXAxisPlayer2,frame1Map->moveInYAxisPlayer2, frame1Map->fieldsVector[0]));
			frame1Map->players.push_back(new Player(player_frame3->playerNameInput->Text, 200, frame1Map->player3, frame1Map->moveInXAxisPlayer3,frame1Map->moveInYAxisPlayer3, frame1Map->fieldsVector[0]));
			frame1Map->players.push_back(new Player(player_frame4->playerNameInput->Text, 200, frame1Map->player4, frame1Map->moveInXAxisPlayer4,frame1Map->moveInYAxisPlayer4, frame1Map->fieldsVector[0]));
    }
}



void __fastcall TstartgameMenu_frame::plus_buttonClick(TObject *Sender)
{
	if (number->ImageIndex < 2)
	{
		number->ImageIndex++;
        (*it)->next_buttonClick(*it);
		(*it)->Visible = true;
		it++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TstartgameMenu_frame::minus_buttonClick(TObject *Sender)
{
	if (number->ImageIndex > 0)
	{
		number->ImageIndex--;
        it--;
		(*it)->Visible = false;

	}
}
//---------------------------------------------------------------------------


