#pragma once

#include <string>

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
					const string DIALOGS[4] = 
					{ 
						"Hello there, my Name is Alphonse Idran, can you tell me yours for have a correct conversation ?\n\n",
						"Nice to meet you {NAME}. I guess you need to know what happening here\n\n...\n\nI'm stuck here\n\n....\n\nIt's a maze...\n\nyou can't see it\n\n",
						"I can see and hear but I can't move, I can just write here for talking with you.\n\nBut you can help if you tell me where to go I will.\n\nI already lived that I guess...\n\nYou know what ? write help for see how to use this console.\n\n",
						"Ok let's start then\n\n",
					};

					/// <summary>
					/// All errors dialogs of AI
					/// </summary>
					const string ERROR_DIALOGS[2] =
					{
						"Write something please or I can't know.",
						"No write help please\n\n",
					};
					
					/// <summary>
					/// Index of the current dialog
					/// </summary>
					int mDialogIndex;

				public:
					/// <summary>
					/// If AI waiting for an answer or not
					/// </summary>
					bool waitingAnswer;

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


