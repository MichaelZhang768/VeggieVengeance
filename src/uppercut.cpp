#include "uppercut.hpp"

Uppercut::Uppercut(int id, vec2 pos, vec2 size, unsigned int damage, bool direction, float vert_force, float ms) {
	//variable bullet attributes
	this->m_fighter_id = id;
	this->m_position = pos;
	this->m_damage = damage;

	//no sprite for punch, not relevant
	this->m_scale = vec2({ 0.0, 0.0 });
	this->m_velocity = vec2({ 0.0, 0.0 });
	
	this->m_width = size.x;
	this->m_height = size.y;
	this->m_delete_when = AFTER_TIME;
	this->m_damageEffect = new DamageEffect(this->m_position.x, this->m_position.y, this->m_width, this->m_height, this->m_damage, this->m_fighter_id, this->m_delete_when, vert_force, ms);
}

Uppercut::~Uppercut() {
	delete m_damageEffect;
}

bool Uppercut::init() {
	return true;
}
void Uppercut::update(float ms) {
	m_damageEffect->m_time_remain--;
	return;
}

void Uppercut::draw(const mat3 &projection){
	return;
}