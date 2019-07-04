#include "pch.h"
#include "Body.h"

//name = Body`s Name
//file = Texture file location
//SpriteGrid = Set the number of sprintes in the texture
//target = target position in the texture
//position = Sprite position in the texture
Body::Body(std::string name, sf::Texture* texture, sf::Vector2i SpriteGrid, sf::Vector2i target, sf::Vector2f position)
{
	this->Texture = texture;
	this->Name = name;
	this->SpriteGrid = SpriteGrid;
	this->Sprite.setTexture(*Texture);
	this->SpriteRect.width = Texture->getSize().x / SpriteGrid.x;
	this->SpriteRect.height = Texture->getSize().y / SpriteGrid.y;
	this->SpriteRect.left = SpriteRect.width * target.x ;
	this->SpriteRect.top = SpriteRect.height * target.y ;
	this->Sprite.setTextureRect(SpriteRect);
	this->Sprite.setPosition(position);
}

Body::Body(sf::Texture* texture, sf::Vector2i SpriteGrid, sf::Vector2i target, sf::Vector2f position)
{
	Body("generic", texture, SpriteGrid, target, position);
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
			if (CurrentSprite.x >= SpriteGrid.x-1)
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
	CurrentSprite.y = SpriteGrid.y-1;
	if (AnimationClock.getElapsedTime().asSeconds() >= AnimationSpeed) {
		AnimationClock.restart();

		if (CurrentSprite.x >= SpriteGrid.x-1) {
			CurrentSprite.x = 0;
			return true;
		}


		this->ChangeSprite(CurrentSprite);
		CurrentSprite.x++;
	}
	this->ChangeSprite(CurrentSprite);
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
	float thistop = this->GetRectangle().top, thisleft = this->GetRectangle().left, 
		thisright = this->GetRectangle().left + this->GetRectangle().width, 
		thisbottom = this->GetRectangle().top + this->GetRectangle().height,
		bodytop = body->GetRectangle().top, bodyleft = body->GetRectangle().left,
		bodyright = body->GetRectangle().left + body->GetRectangle().width,
		bodybottom = body->GetRectangle().top + body->GetRectangle().height;

	if ((thistop > bodytop && thistop < bodybottom) || (thisbottom < bodytop && thisbottom > bodybottom)) {
		if (thisright + 1 >= bodyleft && thisleft < bodyleft)
			this->Colision.RIGHT = true;
		else
			this->Colision.RIGHT = false;

		if (thisleft - 1 >= bodyright && thisright < bodyright)
			this->Colision.LEFT = true;
		else
			this->Colision.LEFT = false;
	}

	if ((thisleft > bodyleft && thisleft < bodyright) || (thisright > bodyleft && thisright < bodyright)) {
		if (thisbottom + 1 >= bodytop && thistop < bodytop)
			this->Colision.BOTTOM = true;
		else
			this->Colision.BOTTOM = false;

		if (thistop - 1 <= bodybottom && thisbottom < bodybottom)
			this->Colision.TOP = true;
		else
			this->Colision.TOP = false;
	}

	return this->GetRectangle().intersects(body->GetRectangle());
}

bool Body::IsExploding()
{
	return Exploding;
}