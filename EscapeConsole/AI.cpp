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
				mWaitingDirectionChose = false;
				isEnd = false;
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

				if (mDialogIndex == 4)
				{
					isEnd = mLevel.IsOnExit();
					waitingAnswer = isEnd == false;
					mWaitingDirectionChose = waitingAnswer;
				}

				if (mWaitingDirectionChose)
				{
					string lSubText = "";
					bool lHaveFirstMove = false;
					bool lHaveSecondMove = false;

					if (mLevel.CanMove(Direction::LEFT))
					{
						lSubText = DIRECTIONS[Direction::LEFT] + ".\n\n";
						lHaveFirstMove = true;
					}

					if (mLevel.CanMove(Direction::BOTTOM))
					{

						if (lHaveFirstMove)
						{
							lSubText.insert(0, " and ");
							lHaveSecondMove = true;
						}
						else
						{
							lSubText = ".\n\n";
							lHaveFirstMove = true;
						}

						lSubText.insert(0, DIRECTIONS[Direction::BOTTOM]);
					}

					if (mLevel.CanMove(Direction::RIGHT))
					{

						if (lHaveSecondMove)
						{
							lSubText.insert(0, ", ");
						}
						else if(lHaveFirstMove)
						{
							lSubText.insert(0, " and ");
							lHaveSecondMove = true;
						}
						else
						{
							lSubText = ".\n\n";
							lHaveFirstMove = true;
						}
						lSubText.insert(0, DIRECTIONS[Direction::RIGHT]);
					}

					if (mLevel.CanMove(Direction::TOP))
					{
						if (lHaveSecondMove)
						{
							lSubText.insert(0, ", ");
						}
						else if (lHaveFirstMove)
						{
							lSubText.insert(0, " and ");
						}
						else
						{
							lSubText = ".\n\n";
						}

						lSubText.insert(0, DIRECTIONS[Direction::TOP]);
					}

					lNextDial = CAN_MOVE_DIALOG;
					lNextDial.append(lSubText);
				}
				else if (mDialogIndex < lDialogsSize) 
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

						pPlayerAnswer[0] = toupper(pPlayerAnswer[0]);
						GameManager::PLAYER_NAME = pPlayerAnswer;
						break;
					case 2:
						if (pPlayerAnswer.empty() || pPlayerAnswer.compare(GameManager::HELP) != 0)
						{
							return ERROR_DIALOGS[1];
						}
						break;
					case 3:
						for (int i = 0, l = pPlayerAnswer.length(); i < l; i++)
						{
							pPlayerAnswer[i] = tolower(pPlayerAnswer[i]);
						}

						Direction lDir;

						if (pPlayerAnswer.compare(DIRECTIONS[Direction::LEFT]) == 0)
						{
							lDir = Direction::LEFT;
						}
						else if (pPlayerAnswer.compare(DIRECTIONS[Direction::BOTTOM]) == 0)
						{
							lDir = Direction::BOTTOM;
						}
						else if (pPlayerAnswer.compare(DIRECTIONS[Direction::RIGHT]) == 0)
						{
							lDir = Direction::RIGHT;
						}
						else if (pPlayerAnswer.compare(DIRECTIONS[Direction::TOP]) == 0)
						{
							lDir = Direction::TOP;
						}
						else 
						{
							return ERROR_DIALOGS[2];
						}

						if (mLevel.CanMove(lDir))
						{
							mLevel.Move(lDir);
							break;
						}

						return ERROR_DIALOGS[3];
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
				delete& mLevel;
			}
		}
	}
}