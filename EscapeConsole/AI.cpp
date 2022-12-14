#include "AI.h"
#include "Constants.h"
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
			/// <returns></returns>
			const string AI::GetNextDialog() 
			{
				string lNextDial = "";

				int lDialogsSize = (int)size(DIALOGS);

				waitingAnswer = mDialogIndex == 0 || mDialogIndex == 2;

				if (mDialogIndex < lDialogsSize) 
				{ 
					lNextDial = DIALOGS[mDialogIndex];
					mDialogIndex++;
					int lIndexOfReplace = (int)lNextDial.find(Fr::MatthiasDeToffoli::EscapeConsole::Utils::Constants::String::REPLACE_PLAYER_NAME);
					if (lIndexOfReplace > 0 && !GameManager::PLAYER_NAME.empty())
					{
						lNextDial.replace(lIndexOfReplace, Fr::MatthiasDeToffoli::EscapeConsole::Utils::Constants::String::REPLACE_PLAYER_NAME.size(), GameManager::PLAYER_NAME);
					}
				}
				return lNextDial;
			}

			/// <summary>
			/// Test the player answer, get the error dialog corresponding if there an error or the next dialog
			/// </summary>
			/// <param name="pPlayerAnswer">the player answer</param>
			/// <returns>the error dialog corresponding if there an error or the next dialog</returns>
			const string AI::TestPlayerAnswer(string pPlayerAnswer) 
			{
				switch (mDialogIndex - 1)
				{
					case 0:
						if (pPlayerAnswer.empty())
						{
							return ERROR_DIALOGS[0];
						}

						pPlayerAnswer[0] = std::toupper(pPlayerAnswer[0]);
						GameManager::PLAYER_NAME = pPlayerAnswer;
						break;
					case 2:
						if (pPlayerAnswer.empty() || pPlayerAnswer.compare(GameManager::HELP) != 0)
						{
							return ERROR_DIALOGS[1];
						}
						break;
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