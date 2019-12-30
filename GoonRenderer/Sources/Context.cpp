#include "Context.h"

#include "Resource/Resource.h"

namespace gr
{
    template <> gr::Context* Singleton<Context>::instance = nullptr;

    Context::Context(int numResLimit)
    {
        //! set this instance ,which is about to be constructed, as singleton pointer.
        instance = this; 
        //! push the numbers which are ranged from 1 to numResLimit in the stack in a reverse order.
        for (int i = numResLimit; i >= 0; --i) 
            idStack.push(i);
    }

    Context::~Context() noexcept
    {   
        //! unload and deallocate all resource
        for (std::pair<GoonID, Resource*> resPair : resources)
        {
            Resource* res = resPair.second;
            res->unload();
            delete res;
        }
        resources.clear();
    }

    void Context::destroyResource(Resource* res) noexcept
    {
        //! get the id from the given resource pointer and find iterator from the resource map with id.
        GoonID id = res->getID();
        auto iter = resources.find(id);
        //! in the case the resource pointer exists in the resource map.
        if (iter != resources.end())
        {
            res->unload();
            delete res;
            resources.erase(iter);
            idStack.push(id);
        }
    }
};