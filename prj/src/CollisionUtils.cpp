#include "CollisionUtils.h"
#include <algorithm>
#include <cmath>

// 点から線への最短ベクトルを取得
static Vec2<float> GetVectorFromPointToLine(const Vec2<float>& point, const Vec2<float>& lineStart, const Vec2<float>& lineEnd)
{
	Vec2<float> lineVec = lineEnd - lineStart;    // 線ベクトル
	Vec2<float> pointVec = point - lineStart;     // 線の始点から点までのベクトル

	// 線分上の最近接点の割合 (0～1)
	float t = std::clamp(pointVec.Dot(lineVec) / lineVec.Dot(lineVec), 0.0f, 1.0f);

	// 線分上の最近接点
	// 始点からt分進んだ位置
	Vec2<float> closestPoint = lineStart + lineVec * t;

	// 点から最近接点へのベクトル
	return point - closestPoint;
}

bool CheckCircleWithWall(const Vec2<float>& circlePos, float circleRadius, const Wall& wall, Vec2<float>& outPush)
{
	// 壁の4辺
	Vec2<float> edges[4][2] = {
		{wall.leftUp, wall.rightUp},
		{wall.rightUp, wall.rightDown},
		{wall.rightDown, wall.leftDown},
		{wall.leftDown, wall.leftUp}
	};

	// 最小値を求めるため最大値で初期化
	float minDistSq = std::numeric_limits<float>::max();
	// 近い線の点から最近接点へのベクトル
	Vec2<float> nearVec(0.0f, 0.0f);
	// 当たっているか
	bool collided = false;

	// 各辺との距離をチェック
	for (int i = 0; i < 4; ++i)
	{
		//  点から線へのベクトル
		Vec2<float> vecToEdge = GetVectorFromPointToLine(circlePos, edges[i][0], edges[i][1]);
		// ベクトルの長さ取得
		float distSq = vecToEdge.GetLengthSq();

		// 一番近い線更新
		if (distSq < minDistSq)
		{
			minDistSq = distSq;
			nearVec = vecToEdge;
		}
	}
	// 近い線の点から最近接点への距離が半径以下なら衝突
	float dist = std::sqrt(minDistSq);
	if (dist <= circleRadius)
	{
		collided = true;

		// 押し戻しベクトルを計算
		if (dist != 0.0f)
		{
			outPush = nearVec.Normalize() * (circleRadius - dist);
		}
		else
		{
			// 点が線上に重なる場合
			outPush = Vec2<float>(0, 0);
		}
	}
	else
	{
		outPush = Vec2<float>(0, 0);
	}

	return collided;
}
