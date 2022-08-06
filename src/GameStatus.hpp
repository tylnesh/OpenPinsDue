class GameStatus {

    public:
  int round;
  int ballsThrown;
  int score;
  bool pinState[9];

  void resetPins(){
    for (int i = 0; i<9; i++) {
      pinState[i] = false;
    }
  }
 
  };