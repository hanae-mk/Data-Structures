
#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{

	cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

	clsMyString S1;

	cout << "\nS1 = " << S1.Value << "\n";

	S1.Value = "Hanae";

	cout << "S1 = " << S1.Value << "\n";

	S1.Value = "Messari";

	cout << "S1 = " << S1.Value << "\n";

	S1.Value = "Khali";

	cout << "S1 = " << S1.Value << "\n";

	cout << "\n\nUndo : ";
	cout << "\n_________\n";

	S1.Undo();
	cout << "\nS1 After Undo : " << S1.Value << "\n";

	S1.Undo();
	cout << "\nS1 After Undo : " << S1.Value << "\n";

	S1.Undo();
	cout << "\nS1 After Undo : " << S1.Value << "\n";

	cout << "\n\nRedo : ";
	cout << "\n_________\n";

	S1.Redo();
	cout << "\nS1 After Redo : " << S1.Value << "\n";

	S1.Redo();
	cout << "\nS1 After Redo : " << S1.Value << "\n";

	S1.Redo();
	cout << "\nS1 After Redo : " << S1.Value << "\n";


	system("pause>0");
	return 0;

}