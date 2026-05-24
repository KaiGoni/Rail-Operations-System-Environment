#include "track.h"
#include <cmath>

sf::Vector2f getBezierPoint(
        const sf::Vector2f& p0,
        const sf::Vector2f& p1,
        const sf::Vector2f& p2,
        float t) {
    float u = 1.f - t;
    return u*u * p0 + 2.f*u*t * p1 + t*t * p2;
}

bool Track::validTrack() {
    if (!startNode) return false;
    if (!endNode) return false;
    if (trackType == TrackType::Bezier && !controlPoint) return false;
    return true;
}
void Track::buildSubnodes() { // Note: This might have issues with linear
    if (!validTrack()) return;
    subnodes.clear();
    const int segments = 100;
    float totalLength = 0.f;
    sf::Vector2f prev = startNode->pos;

    for (int i = 1; i <= segments; i++) {
        float u = (float)i / segments;

        sf::Vector2f curr;

        if (trackType == TrackType::Linear) {
            curr = startNode->pos +
                   (endNode->pos - startNode->pos) * u;
        } else {
            curr = getBezierPoint(
                startNode->pos,
                controlPoint.value(),
                endNode->pos,
                u
            );
        }

        float segmentLength = std::sqrt(std::pow(curr.x - prev.x, 2) + std::pow(curr.y - prev.y, 2));
        totalLength += segmentLength;

        subnodes.push_back({curr, totalLength, std::atan2(curr.y - prev.y, curr.x - prev.x)});
        prev = curr;
    }
    cachedLength = totalLength;
    nodeCached = true;
}
float Track::length() {
    if (nodeCached) return cachedLength;
    if (!validTrack()) return -1.0f;
    buildSubnodes();
    return cachedLength;
}
sf::Vector2f Track::getPos(float dist) {
    if (!validTrack()) return sf::Vector2f(0.f, 0.f);
    if (trackType == TrackType::Linear) {
        float t = dist / std::sqrt(std::pow(endNode->pos.x - startNode->pos.x, 2) + std::pow(endNode->pos.y - startNode->pos.y, 2));
        return startNode->pos + t * (endNode->pos - startNode->pos);
    } else if (trackType == TrackType::Bezier)
    {
        if (!nodeCached) buildSubnodes();
        for (const auto& point : subnodes) {
            if (point.length >= dist) {
                return point.pos;
            }
        }
        return endNode->pos; // If distance exceeds track length, return end position
    }
    return sf::Vector2f(0.f, 0.f);
}
float Track::getAngle(float dist) {
    if (!validTrack()) return -1.0f;
    if (trackType == TrackType::Linear) {
        sf::Vector2f dir = endNode->pos - startNode->pos;
        return std::atan2(dir.y, dir.x);
    } else if (trackType == TrackType::Bezier) {
        if (!nodeCached) buildSubnodes();
        for (const auto& point : subnodes) {
            if (point.length >= dist) {
                return point.angle;
            }
        }
        return 0.0f;
    }
    return 0.0f;
}