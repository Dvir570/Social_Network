#include <map>
using namespace std;

class Member{
    private:
        static unsigned int ACTIVE_MEMBERS;
        static unsigned int COUNTER_ID;
        unsigned int id;
        unsigned int followers;
        unsigned int following;
        map<unsigned int, Member*> followers_list;
        map<unsigned int, Member*> following_list;
        
    public:
        Member();
        void follow(Member& m);
        void unfollow(Member& m);
        unsigned int numFollowing() const;
        unsigned int numFollowers() const;
        static unsigned int count();
        ~Member();
};