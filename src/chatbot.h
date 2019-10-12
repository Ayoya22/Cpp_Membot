#ifndef CHATBOT_H_
#define CHATBOT_H_

#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *picture; // avatar imagez

    // data handles (not owned)
    ChatLogic *_chatLogic;
    GraphNode *_currentNode;
    GraphNode *_rootNode;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    ChatBot(const ChatBot &source);//copy constructor declaration
    ChatBot( ChatBot &&source);//move constructor declaration
    ChatBot &operator=(const ChatBot &source);//copy assignment operator declaration
    ChatBot &operator=(ChatBot &&source);//move assignment operator declaration

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return picture; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */