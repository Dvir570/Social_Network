#include "Member.h"
#include <iterator>

Member::ACTIVE_MEMBERS = 0;
Member::COUNTER_ID = 1;

Member::Member(){
    this->following = 0;
    this->followers = 0;
    this->id = COUNTER_ID;
    COUNTER_ID++;
    ACTIVE_MEMBERS++;
}

void Member::follow(Member& m) 
{
    //checking if "this" already follows him
    if(this->following_list.count(m.id) > 0)
        return;
    
    this->following_list.insert(m.id, &m);
    this->following++;
    
    m.followers_list.insert(this->id, &this);
    m.followers++;
}

void Member::unfollow(Member& m)
{
    //checking if "this" does not follow him
    if(this->following_list.count(m.id) = 0)
        return;
        
    this->following_list.erase(m.id);
    this.following--;
    
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

static unsigned int Member::count() const
{
    return ACTIVE_MEMBERS;
}

Member::~Member(){
    map<unsigned int, Member&>::iterator itr;
    for(itr = this->followers_list.begin(); itr != this->followers_list.end(); ++itr )
    {
        Member* m = itr->second;
        m->following_list.erase(this->id);
        m->following--;
        delete m;
    }
    
    for(itr = this->following_list.begin(); itr != this->following_list.end(); ++itr)
    {
        Member* m = itr->second;
        m->followers_list.erase(this->id);
        m->followers--;
        delete m;
    }
    
    
    ACTIVE_MEMBERS--;
}