#include "Transform.h"



Transform::Transform(): pParent_(nullptr)
{
	position_ = XMFLOAT3(0, 0, 0);
	rotate_ = XMFLOAT3(0, 0, 0);
	scale_ = XMFLOAT3(1, 1, 1);
	matTranslate_ = XMMatrixIdentity();//単位行列
	matRotate_ = XMMatrixIdentity();
	matScale_ = XMMatrixIdentity();
	isUseWorldMatrix_ = false;
	matWorld_ = XMMatrixIdentity();
}


Transform::~Transform()
{
}

void Transform::Calclation()
{
	//移動行列
	matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

	//回転行列
	XMMATRIX rotateX, rotateY, rotateZ;
	//XMConvertToDegrees() ラジアンから度
	rotateX = XMMatrixRotationX(XMConvertToRadians(rotate_.x));
	rotateY = XMMatrixRotationY(XMConvertToRadians(rotate_.y));
	rotateZ = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));
	matRotate_ = rotateZ * rotateX * rotateY;

	//拡大縮小
	matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

void Transform::SetWorldMatrix(XMMATRIX matrix)
{
	isUseWorldMatrix_ = true;
	matWorld_ = matrix;
}

void Transform::UseTransformParameter()
{
	isUseWorldMatrix_ = false;
}

XMMATRIX Transform::GetWorldMatrix() 
{
	XMMATRIX world;

	if (isUseWorldMatrix_)
	{
		world = matWorld_;
	}
	else
	{
		Calclation();
		world = matScale_ * matRotate_ * matTranslate_;
	}

	if (pParent_)
	{
		return  world * pParent_->GetWorldMatrix();
	}

	return  world;
}

