#include "track.h"
#include "editor/interface.h"
#include "gui/panelManager.h"

std::vector<Node> nodes;
std::vector<Track> tracks;

void drawNode(sf::RenderWindow& window, const Node& node) {
    sf::CircleShape circle(6.f);
    circle.setOrigin(6.f, 6.f);
    circle.setPosition(node.pos);
    circle.setFillColor(sf::Color::Red);

    window.draw(circle);
}

void drawTrack(sf::RenderWindow& window, Track& t) {
    if (!t.validTrack()) return;

    const int segments = 100;

    sf::Vector2f prev = t.startNode->pos;

    for (int i = 1; i <= segments; i++) {
        float u = (float)i / segments;

        sf::Vector2f curr;

        if (t.trackType == Track::TrackType::Linear) {
            curr = t.startNode->pos +
                   (t.endNode->pos - t.startNode->pos) * u;
        } else {
            curr = getBezierPoint(
                t.startNode->pos,
                t.controlPoint.value(),
                t.endNode->pos,
                u
            );
        }

        sf::Vertex line[] = {
            sf::Vertex(prev, sf::Color::White),
            sf::Vertex(curr, sf::Color::White)
        };

        window.draw(line, 2, sf::Lines);

        prev = curr;
    }
}

void drawScreen(sf::RenderWindow &window) {
    for (auto& track : tracks) {
        drawTrack(window, track);
    }
    for (const auto& node : nodes) {
        drawNode(window, node);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Rail Operations System Environment");

    // Temp tracks
    Node a;
    a.id = 1;
    a.pos = {200, 300};

    Node b;
    b.id = 2;
    b.pos = {600, 500};

    Node c;
    c.id = 3;
    c.pos = {1000, 200};

    Track t1;
    t1.startNode = &a;
    t1.endNode = &b;
    t1.trackType = Track::TrackType::Linear;

    Track t2;
    t2.startNode = &b;
    t2.endNode = &c;
    t2.trackType = Track::TrackType::Bezier;
    t2.controlPoint = sf::Vector2f(800, 700);

    nodes = {a, b, c};
    tracks = {t1, t2};

    EditorInterface editor(window);

    while (window.isOpen()) {   // Main Loop
        sf::Event event;        // Event handler
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                editor.onScreenResized(window);
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        drawScreen(window);
        editor.draw(window);

        window.display();
    }

    return 0;
}