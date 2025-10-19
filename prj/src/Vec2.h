#pragma once  
#include <DxLib.h>
#include <cmath>  

// 2D�x�N�g���N���X  
template<typename T>
class Vec2
{
public:

	T x, y;

	// �R���X�g���N�^  
	Vec2(T arg_x = 0, T arg_y = 0) : x(arg_x), y(arg_y) {}
	Vec2(const Vec2& v2) : x(v2.x), y(v2.y) {}

	// �l�ݒ�
	void Set(T arg_x, T arg_y) { x = arg_x; y = arg_y; }

	// �����擾  
	T GetLength() const { return std::sqrt(x * x + y * y); };
	// �����̂Q��擾
	T GetLengthSq() const { return x * x + y * y; };

	// ���K��  
	Vec2<T> Normalize();

	// ���ώ擾
	T Dot(const Vec2& f2) const { return x * f2.x + y * f2.y; }

	// ���Z�q�I�[�o�[���[�h
	Vec2& operator =  (const Vec2& f2);                    // = ���Z�q�̃I�[�o�[���[�h  
	Vec2& operator += (const Vec2& f2);                    // += ���Z�q�̃I�[�o�[���[�h  
	Vec2& operator -= (const Vec2& f2);                    // -= ���Z�q�̃I�[�o�[���[�h  
	Vec2& operator *= (const Vec2& f2);                    // *= ���Z�q�̃I�[�o�[���[�h  
	Vec2& operator /= (const Vec2& f2);                    // /= ���Z�q�̃I�[�o�[���[�h  
};

// ���K��
template<typename T>
inline Vec2<T> Vec2<T>::Normalize()
{
	// �x�N�g���̒������擾
	float length = GetLength();

	// �O�̂Ƃ��͂��̂܂ܕԂ�
	if (length == 0.0f)
		return Vec2<T>(0, 0);

	// �����Ŋ���
	x /= length;
	y /= length;

	// ���K����̃x�N�g����Ԃ�
	return Vec2<T>(x, y);

}

// = ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T>& Vec2<T>::operator=(const Vec2<T>& f2)
{
	x = f2.x;
	y = f2.y;
	return *this;
}

// += ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& f2)
{
	x += f2.x;
	y += f2.y;
	return *this;
}

// -= ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T>& Vec2<T>::operator-=(const Vec2<T>& f2)
{
	x -= f2.x;
	y -= f2.y;
	return *this;
}

// *= ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T>& Vec2<T>::operator*=(const Vec2<T>& f2)
{
	x *= f2.x;
	y *= f2.y;
	return *this;
}

// /= ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T>& Vec2<T>::operator/=(const Vec2<T>& f2)
{
	x /= f2.x;
	y /= f2.y;
	return *this;
}

// + ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T> operator+(const Vec2<T>& f2_1, const Vec2<T>& f2_2)
{
	return Vec2<T>(f2_1.x + f2_2.x, f2_1.y + f2_2.y);
}

// - ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T> operator-(const Vec2<T>& f2_1, const Vec2<T>& f2_2)
{
	return Vec2<T>(f2_1.x - f2_2.x, f2_1.y - f2_2.y);
}

// * ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T> operator*(const Vec2<T>& f2, const float f)
{
	return Vec2<T>(f2.x * f, f2.y * f);
}

// / ���Z�q�̃I�[�o�[���[�h  
template<typename T>
Vec2<T> operator/(const Vec2<T>& f2, const float f)
{
	return Vec2<T>(f2.x / f, f2.y / f);
}


// �}�E�X�̍��W�����  
template<typename T>
void GetMousePos(T& x, T& y)
{
	int mouse_x, mouse_y;
	GetMousePoint(&mouse_x, &mouse_y);

	x = static_cast<T>(mouse_x);
	y = static_cast<T>(mouse_y);
}