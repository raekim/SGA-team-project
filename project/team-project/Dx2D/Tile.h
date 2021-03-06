﻿#pragma once
#include "MyTriangle.h"
class Tile : public iGameNode
{
	D3DXVECTOR2 m_tilePos;	// 렌더 및 충돌처리용 좌표
	bool m_hasRectCollider;
public:
	// collider, sprite는 template으로부터 공유하고 있으므로 사용 시 주의!
	Rect* m_rectCollider;
	MyTriangle* m_triangleCollider;
	Sprite* m_sprite;
	Tile(Sprite* s);
	Tile();
	~Tile();

	virtual void Init() override;
	bool CollisionWithCircle(Circle * other);
	virtual void Update() override;
	virtual void Update(D3DXVECTOR2 tilePos);
	virtual void Render() override;
	virtual void Release() override;

	void SetRectCollider();	// sprite 사이즈에 맞는 rect를 생성하여 collider로써 가지고 있는다
	void SetRectCollider(Rect* rect);
	void SetTriangleCollider(vector<PCVertex> m_vecVertex);	// 삼각형 collider 설정
};

