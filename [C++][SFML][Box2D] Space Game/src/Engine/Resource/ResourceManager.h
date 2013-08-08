#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <map>
#include <memory>

#include "..\DBG\dbgmsg.h"

template<typename T>
class ResourceManager
{
protected:
	std::string m_directoryPath;
	std::map< std::string , std::unique_ptr< T > >  m_resourceMap;
	virtual bool load( const std::string &name ) = 0;
public:
	ResourceManager( const std::string &directoryPath );
	virtual ~ResourceManager();
	T& get( const std::string &name );
	void preload( const std::string &name );
	void erase( const std::string &name );
};

template<typename T>
ResourceManager<T>::ResourceManager( const std::string &path ) : m_directoryPath(path)
{}

template<typename T>
ResourceManager<T>::~ResourceManager()
{
	m_resourceMap.clear();
}

template<typename T>
T& ResourceManager<T>::get( const std::string &name )
{
	preload(name);
	return *m_resourceMap.at(name);
}

template<typename T>
void ResourceManager<T>::preload( const std::string &name )
{
	if(m_resourceMap.empty() || m_resourceMap.find(name) == m_resourceMap.end())
	{
		DBGMSGR("Loading resource" << name);
		if(!load(name))
		{
			DBGMSGR("Couldn't load resource " << name);
			std::exit(EXIT_FAILURE);
		}
	}
}

template<typename T>
void ResourceManager<T>::erase( const std::string &name )
{
	DBGMSGR("Erasing resource " << name);
}
#endif // RESOURCEMANAGER_H
