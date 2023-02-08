#pragma once

#include <string>
#include "Level.h"

using namespace std;

namespace Fr
{
	namespace MatthiasDeToffoli
	{
		namespace EscapeConsole
		{
			class AI
			{
				private:
					/// <summary>
					/// All dialogs of AI except errors dialogs
					/// </summary>
					const string DIALOGS[5] = 
					{ 
						"Hello there, my Name is Alphonse Idran, can you tell me yours for have a correct conversation ?\n\n",
						"Nice to meet you {NAME}. I guess you need to know what happening here\n\n...\n\nI'm stuck here\n\n....\n\nIt's a maze...\n\nyou can't see it\n\n",
						"I can see and hear but I can't move, I can just write here for talking with you.\n\nBut you can help if you tell me where to go I will.\n\nI already lived that I guess...\n\nYou know what ? write help for see how to use this console.\n\n",
						"I know the map, you can't see it, you will have to trust me. I will tell you where you can go, you just have to tell me where you want to go and I will make you move\n\n",
						"It's the exit ! Congratulations ! The console will close soon don't reopen it or you will restart like if nothing happened. Goodbye my friend."
					};

					/// <summary>
					/// All errors dialogs of AI
					/// </summary>
					const string ERROR_DIALOGS[4] =
					{
						"Write something please or I can't know.",
						"No write help please\n\n",
						"Write a direction please\n\n",
						"Sorry you can't move there\n\n",
					};

					/// <summary>
					/// string version of directions
					/// </summary>
					const string DIRECTIONS[4] =
					{
						"left",
						"right",
						"top",
						"bottom"
					};
					
					
					/// <summary>
					/// Dialog sentence for say which direction the player can move at
					/// </summary>
					const string CAN_MOVE_DIALOG = "You can move at ";

					/// <summary>
					/// Index of the current dialog
					/// </summary>
					int mDialogIndex;

					/// <summary>
					/// Boolean used when AI wait the player choose a direction
					/// </summary>
					bool mWaitingDirectionChose;

					/// <summary>
					/// Current level
					/// </summary>
					Level mLevel;
				public:
					/// <summary>
					/// If AI waiting for an answer or not
					/// </summary>
					bool waitingAnswer;

					/// <summary>
					/// True when the player is at the end of the game
					/// </summary>
					bool isEnd;

					/// <summary>
					/// Default constructor
					/// </summary>
					AI();

					/// <summary>
					/// Get the next dialiog of AI
					/// </summary>
					/// <returns></returns>
					const string GetNextDialog();

					/// <summary>
					/// Test the player answer, get the error dialog corresponding if there an error or the next dialog
					/// </summary>
					/// <param name="pPlayerAnswer">the player answer</param>
					/// <returns>the error dialog corresponding if there an error or the next dialog</returns>
					const string TestPlayerAnswer(string pPlayerAnswer);

					/// <summary>
					/// Default destructor
					/// </summary>
					~AI();
			};
		}
	}
}


