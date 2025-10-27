#include "Environment.h"
#include "Alive.h"
#include "Bullet.h"
#include <tuple>


Environment::Environment(std::vector<Element*> elements)
{
	for (Element* e : elements) {
		((Alive*)e)->setEnv(this);
	}

}

void Environment::clearAllStep()
{
	int nullCount = 0;
	for (int i = 0; i < this->attacks.size(); i++) {
		if (this->attacks[i]->isDispersed) {
			nullCount++;
		}
	}

	if (nullCount == this->attacks.size()) {
		for (int i = 0; i < this->attacks.size(); i++) {
			delete attacks[i];
		}
		attacks.clear();
	}


}

void Environment::sendAttack(Attack* attack)
{
	this->clearAllStep();
	attack->setEnv(this);
	this->attacks.push_back(attack);
	for (Attack* oneAttack : this->attacks) {
		std::cout << oneAttack << std::endl;
	}
	
}

int Environment::getAttackIndexIfAffecting(Alive* target)
{
	if (this->attacks.empty()) {
		return -1;
	}

	bool isAffected = false;

	for (int i = 0; i < this->attacks.size(); i++) {
		if (this->attacks[i]->isRanged) {
			isAffected = this->calc.isRectOnStepPath(target->boundingBox, ((Bullet*)attacks[i])->pos, ((Bullet*)attacks[i])->giveStep());
			if (isAffected) {
				return i;
			}
		}
		else {
			isAffected = this->calc.isVectorInTriangle(target->pos, attacks[i]->orgPos, 10.0f, 10.0f, attacks[i]->rotation);
			if (isAffected) {
				return i;
			}
		}
	}

	return -1;
}

Attack* Environment::recieveAttack(Alive* target)
{
	if (int index = this->getAttackIndexIfAffecting(target) != -1)
		return this->attacks[index];
	else
		return nullptr;


}
