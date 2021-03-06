#ifndef GAME_H_
#define GAME_H_

#include <boost/scoped_ptr.hpp>

class Map;
class Player;
class Graphics;

class Game {
public:
    Game();
    ~Game();

    static int kTileSize;
private:
    void eventLoop();
    void update(int elapsed_time_ms);
    void draw(Graphics& graphics);

    boost::scoped_ptr<Player> player_;
    boost::scoped_ptr<Map> map_;
};

#endif // GAME_H_
