#include "collision.h"
#include "colliderComponent.h"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{

    if (rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x) {
        // Check for vertical collision
        if (rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y) {
            return true;
        }
    }
    return false;

}

bool Collision::AABB(const ColliderComponent& colliderComponentA, const ColliderComponent& colliderComponentB)
{

    if (AABB(colliderComponentA.collider, colliderComponentB.collider))
    {
        if (colliderComponentA.tag == colliderComponentB.tag) return false;
        std::cout << colliderComponentA.tag << " hit: " << colliderComponentB.tag << std::endl;
        return true;
    }
    return false;

}
