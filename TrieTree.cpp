#include "TrieTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void addWord(trieTreeNode* root, const string word, const int id)
{
	if(word.size() == 0)
	{
		//在每个单词的最后一个节点增加词频
		root->freq++;
		return;
	}

	int index = word[0] - 'a';
	if(root->pNode[index] == NULL)
	{
		root->pNode[index] = new trieTreeNode();
	}
	
	//在单词路径上的每个节点添加ID
	root->pNode[index]->setStringID.insert(id);

	string tempWord = word.substr(1);
	addWord(root->pNode[index], tempWord, id);
}


void deleteWord(trieTreeNode* root, const string word, const int id)
{
	if(word.size() == 0)
	{
		//在每个单词的最后一个节点减少词频
		root->freq--;
		return;
	}

	int index = word[0] - 'a';

	if(root->pNode[index] == NULL)
		return;

	//在单词路径上的每个节点删去ID
	root->pNode[index]->setStringID.erase(id);

	string tempWord = word.substr(1);
	deleteWord(root->pNode[index], tempWord, id);
}


int searchFreq(trieTreeNode* root, const string word)
{
	if(word.size() == 0)
		 return root->freq;

	int index = word[0] - 'a';

	if(root->pNode[index] == NULL)
		return -1;

	string tempWord = word.substr(1);
	return searchFreq(root->pNode[index], tempWord);
}


void createTree(trieTreeNode* root, const vector<string> &vecStr)
{
	int num = 0;
	for(vector<string>::const_iterator iter = vecStr.begin(); iter != vecStr.end(); iter++)
	{
		addWord(root, *iter, num++);
	}
}


int main()
{
	vector<string> vecStr;
	string str;

	ifstream ifs("input.txt"); //输入流
	istream_iterator<string> iterString(ifs);
	istream_iterator<string> iterEOF;
	vector<string> vecFile(iterString, iterEOF);
	ifs.close();

	trieTreeNode* root = new trieTreeNode();
	createTree(root, vecFile);

	cout << searchFreq(root, "cn") << endl;

	deleteWord(root, "cn", 3);

	cout << searchFreq(root, "cn") << endl;

	return 0;
}