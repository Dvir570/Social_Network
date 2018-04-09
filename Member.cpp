#include "Member.hpp"
#include <iterator>

unsigned int Member::ACTIVE_MEMBERS = 0;
unsigned int Member::COUNTER_ID = 1;

Member::Member(){
    this->following = 0;
    this->followers = 0;
    this->id = COUNTER_ID;
    COUNTER_ID++;
    ACTIVE_MEMBERS++;
}

void Member::follow(Member& m) 
{
    //checking if "this" tried to follow himself
    if(this->id == m.id)
        return;
        
    //checking if "this" already follows him
    if(this->following_list.count(m.id) > 0)
        return;
    
    this->following_list.insert(pair<unsigned int, Member*>(m.id, &m));
    this->following++;
    
    m.followers_list.insert(pair<unsigned int, Member*>(this->id, this));
    m.followers++;
}

void Member::unfollow(Member& m)
{
    //checking if "this" tried to unfollow himself
    if(this->id == m.id)
        return;
        
    //checking if "this" does not follow him
    if(this->following_list.count(m.id) == 0)
        return;
        
    this->following_list.erase(m.id);
    this->following--;
    
    m.followers_list.erase(this->id);
    m.followers--;
}

unsigned int Member::numFollowing() const
{
        return this->following;
}

unsigned int Member::numFollowers() const
{
    return this->followers;
}

unsigned int Member::count()
{
    return ACTIVE_MEMBERS;
}

Member::~Member()
{
    map<unsigned int, Member*>::iterator itr;
    for(itr = this->followers_list.begin(); itr != this->followers_list.end(); ++itr )
    {
        Member* m = itr->second;
        m->following_list.erase(this->id);
        m->following--;
    }
    
    for(itr = this->following_list.begin(); itr != this->following_list.end(); ++itr)
    {
        Member* m = itr->second;
        m->followers_list.erase(this->id);
        m->followers--;
    }
    
    
    ACTIVE_MEMBERS--;
}