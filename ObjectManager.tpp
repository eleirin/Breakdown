template<typename U, typename... Args>
U* ObjectManager::add(Args... args)
{
	U *created = new U(args...);
	m_AliveList.push_front(created);
	return created;
}

