#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TRACK_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TRACK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

sf::Vector2f getBezierPoint(
    const sf::Vector2f& p0,
    const sf::Vector2f& p1,
    const sf::Vector2f& p2,
    float t);

struct Node;
struct Track;

struct Connection {
    Node *node = nullptr;
    Track *track = nullptr;
};

struct Node {
    int id = 0;
    sf::Vector2f pos;
    std::vector<Connection> connections;
};

struct Track {
private:
    bool nodeCached = false;
    float cachedLength = 0.f;
    struct subnode{
        sf::Vector2f pos;
        float length;
        float angle;
    };
    std::vector<subnode> subnodes;
public:
    enum class TrackType {
        Linear,
        Bezier
    };
    int id = 0;
    Node *startNode = nullptr;
    Node *endNode = nullptr;
    TrackType trackType = TrackType::Linear;
    std::optional<sf::Vector2f> controlPoint;

    bool validTrack();
    void buildSubnodes();
    float length();
    sf::Vector2f getPos(float dist);
    float getAngle(float dist);
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TRACK_H