#pragma once

#include <atomic>
#include <string>

const int LETTER_COUNT = 26;

struct DictionaryNode
{
    DictionaryNode(DictionaryNode* parent, const char value);
    ~DictionaryNode();

    DictionaryNode* mParent;
    const char mValue;
    bool mIsWord;
    std::atomic_flag mIsDisabled;
    std::atomic<int> mChildrenCount;
    DictionaryNode* mChildren[LETTER_COUNT];
};

class Dictionary
{
public:
    Dictionary(const std::string filePath);
    ~Dictionary();

    const DictionaryNode* getRoot();
    bool addWord(std::string word);
    void removeWord(DictionaryNode* node);
    DictionaryNode* getChild(const DictionaryNode* parent, const char value);

private:
    DictionaryNode* mRoot;
    static int charToIndex(char c);
    static char indexToChar(int index);
};
