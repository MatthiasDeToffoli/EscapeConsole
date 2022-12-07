#include "AI.h"
#include "GameManager.h"
#include <iostream>

namespace Fr
{
	namespace MatthiasDeToffoli
	{
		namespace EscapeConsole
		{
			/// <summary>
			/// Default constructor
			/// </summary>
			AI::AI() 
			{
				mDialogIndex = 0;
				waitingAnswer = false;
			}

			/// <summary>
			/// Get the next dialiog of AI
			/// </summary>
			/// <returns>the next dialog</returns>
			const char* AI::GetNextDialog() 
			{
				const char* lNextDial = "";

				int lDialogsSize = std::size(DIALOGS);

				waitingAnswer = mDialogIndex == 0 || mDialogIndex == 2;

				if (mDialogIndex < lDialogsSize) 
				{
					lNextDial = DIALOGS[mDialogIndex++];
				}
				return lNextDial;
			}

			/// <summary>
			/// Test the player answer, get the error dialog corresponding if there an error or the next dialog
			/// </summary>
			/// <param name="pPlayerAnswer">the player answer</param>
			/// <returns>the error dialog corresponding if there an error or the next dialog</returns>
			const char* AI::TestPlayerAnswer(char* pPlayerAnswer) 
			{
				switch (mDialogIndex)
				{
					case 0:
						if (pPlayerAnswer == NULL || pPlayerAnswer[0] == '\0')
						{
							return ERROR_DIALOGS[0];
						}
						break;
					case 2:
						if (pPlayerAnswer == NULL || strcmp(pPlayerAnswer, GameManager::HELP))
						{
							return ERROR_DIALOGS[1];
						}
					default:
						return "";
				}

				waitingAnswer = false;
				return GetNextDialog();
			}

			/// <summary>
			/// Default destructor
			/// </summary>
			AI::~AI()
			{

			}
		}
	}
}