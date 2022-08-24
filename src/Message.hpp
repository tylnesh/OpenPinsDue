/*
An ARQ-type message including numbering,  ACK/NOACK, etc.
*/

#include "GameStatus.hpp"
class Message {

    public: 
    int count;
    int command;

    //Optional GameStatus for transmiting game data
    GameStatus gameStatus;
 
  };