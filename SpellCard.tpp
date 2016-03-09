/*! \file SpellCard.tpp
 *  \brief Instantiate the template function of SpellCard
 */

/*! \brief Creates a bullet of a certain type
 *
 * This function creates a bullet of type U using as parameter the position, how many explosions has already happened and how many will there be.
 *
 * \tparam U The type of Bullet to be spawned. 
 * Restriction:
 * 	- Must have a constructor U(MathVector, int, int)
 * 	- Must be a subclass of Bullet
 *
 * \return A pointer to the bullet that was created. It can be accessed and modified normally.
 */
template<typename U>
Bullet *SpellCard::spawn(void)
{
	Bullet *created = m_ToSpawn->add<U>(m_Position, m_Number, m_MaxExplosion);
	return created;
}

/*! \brief Spawn several bullets of a certain type.
 *
 * Similar to spawn(void), this function creates duplicates number of bullet of type U using as parameter the position, how many explosions has already happened, the number of this bullet in the spawning process, and the total number of explosion
 *
 *\tparam U The type of Bullet to be spawned. 
 * Restriction:
 * 	- Must have a constructor U(MathVector, int, int, int)
 * 	- Must be a subclass of Bullet
 *
 * \return A list of pointers to all the bullets that were created. Each can be accessed and modified normally.
 */
template<typename U>
std::list<Bullet *> SpellCard::spawn(int duplicates)
{
	std::list<Bullet *> created;

	for(int i = 0; i < duplicates; i++)
	{
		created.push_front(m_ToSpawn->add<U>(m_Position, m_Number, i, m_MaxExplosion));
	}

	return created;
}
