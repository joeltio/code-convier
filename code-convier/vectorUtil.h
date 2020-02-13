#pragma once

#include <d3dx9math.h>
#include <utility>
#include <vector>

char getQuadrant(D3DXVECTOR2& subject, D3DXVECTOR2& reference);
char getQuadrant(D3DXVECTOR2& subject, D3DXVECTOR2& reference, D3DXVECTOR2& axis);
float distance2(D3DXVECTOR2& a, D3DXVECTOR2& b);
bool doExtentsIntersect(std::pair<float, float>& a, std::pair<float, float>& b);
std::pair<float, float> findVectorExtents(std::vector<D3DXVECTOR2> corners, D3DXVECTOR2 normal);
