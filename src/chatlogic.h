#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<GraphNode *> _nodes;
    std::vector<GraphEdge *> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T *element);

    template <typename T>
    T *AddItemToElementList(int id, std::vector<T *> &elements);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetChatbotHandle(ChatBot *chatbot);
    ChatBotPanelDialog *GetChatBotPanelDialog() { return _panelDialog; }
    ChatBot *GetChatBot() {
        return _chatBot;
    }
    void SetPanelDialogHandle(ChatBotPanelDialog *dialog) { _panelDialog = dialog; }

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
};

#endif /* CHATLOGIC_H_ */