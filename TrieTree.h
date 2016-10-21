#include <set>
#include <vector>
using namespace std;

class trieTreeNode
{
public:

	int freq;
	set<int> setStringID;
	trieTreeNode* pNode[26];

	trieTreeNode(): freq(0)
	{		
		for(int i = 0; i < 26; i++)
		{
			pNode[i] = NULL;
		}
	}
};

class trieTree
{
private:
	trieTreeNode* root;
};

void addWord(trieTreeNode* root, const string word, const int id);
void deleteWord(trieTreeNode* root, const string word, const int id);
int searchFreq(trieTreeNode* root, const string word);
void createTree(trieTreeNode* root, const vector<string> &vecStr);