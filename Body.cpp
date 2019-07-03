#include "pch.h"
#include "Body.h"

//name = Body`s Name
//file = Texture file location
//SpriteGrid = Set the number of sprintes in the texture
//target = target position in the texture
//position = Sprite position in the texture
Body::Body(std::string name, std::string file, sf::Vector2i SpriteGrid, sf::Vector2i target, sf::Vector2f position)
{
	this->Sprite.setPosition(position);
	this->Name = name;
	this->Texture.loadFromFile(file);
	this->SpriteGrid = SpriteGrid;
	Sprite.setTexture(Texture);
	SpriteRect.width = Texture.getSize().x / SpriteGrid.x;
	SpriteRect.height = Texture.getSize().y / SpriteGrid.y;
	SpriteRect.left = SpriteRect.width * target.x +1;
	SpriteRect.top = SpriteRect.height * target.y +1;
	Sprite.setTextureRect(SpriteRect);
}

Body::Body(std::string file, sf::Vector2i SpriteGrid, sf::Vector2i target, sf::Vector2f position)
{
	Body("generic", file, SpriteGrid, target, position);
}


void Body::ChangeSprite(sf::Vector2i vect)
{
	this->SpriteRect = this->Sprite.getTextureRect();
	this->SpriteRect.left = vect.x * this->SpriteRect.width;
	this->SpriteRect.top = vect.y * this->SpriteRect.height;
	this->Sprite.setTextureRect(this->SpriteRect);
}



Body::~Body()
{
}

void Body::SetPosition(sf::Vector2f pos)
{
	this->Sprite.setPosition(pos);
}

sf::Vector2f Body::GetPosition()
{
	return this->Sprite.getPosition();
}

void Body::SetName(std::string name)
{
	this->Name = name;
}

std::string Body::GetName()
{
	return this->Name;
}

sf::Sprite Body::GetSprite()
{
	return this->Sprite;
}

sf::Vector2i Body::GetSize()
{
	return sf::Vector2i(this->Sprite.getTextureRect().width, this->Sprite.getTextureRect().height);
}

sf::IntRect Body::GetRectangle()
{
	return this->Sprite.getTextureRect();
}

void Body::Animation()
{
	if (AnimationClock.getElapsedTime().asSeconds() >= AnimationSpeed) {
		AnimationClock.restart();
		if (AnimationFlow) {
			CurrentSprite.x++;
			if (CurrentSprite.x > SpriteGrid.x)
				AnimationFlow = false;
		}
		else{
			CurrentSprite.x--;
			if (CurrentSprite.x <= 0)
				AnimationFlow = true;
		}
		this->ChangeSprite(CurrentSprite);
	}
}

bool Body::DeathAnimation()
{
	CurrentSprite.y = SpriteGrid.y;
	if (AnimationClock.getElapsedTime().asSeconds() >= AnimationSpeed) {
		AnimationClock.restart();

		CurrentSprite.x++;
		if (CurrentSprite.x > SpriteGrid.x)
			return true;

		this->ChangeSprite(CurrentSprite);
	}
	return false;
}

void Body::Move(sf::Vector2f pos)
{
	this->Sprite.setPosition(this->Sprite.getPosition().x + pos.x, this->Sprite.getPosition().y + pos.y);
}

void Body::SetAnimationSpeed(double speed)
{
	this->AnimationSpeed = speed;
}

double Body::GetAnimationSpeed()
{
	return this->AnimationSpeed;
}

bool Body::IsColiding(Body *body)
{
	if (this->GetRectangle().top)

	return this->GetRectangle().intersects(body->GetRectangle());
}
