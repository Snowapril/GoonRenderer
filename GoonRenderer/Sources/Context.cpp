#include "Context.h"


namespace gr
{
    template <> gr::Context* Singleton<gr::Context>::instance = nullptr;

    Context::Context(int numResLimit)
    {
        //! assign this instance to the singleton instance pointer.
        instance = this; 
        //! resize and shrink resource vector to given size.
        resources.resize(numResLimit, nullptr);
        resources.shrink_to_fit();
        //! push the numbers which are ranged from 1 to numResLimit in the stack in a reverse order.
        for (int i = numResLimit; i >= 0; --i) 
            idStack.push(i);
    }

    Context::~Context() noexcept
    {   
        //! unload and deallocate all resource
        for (Resource* res : resources)
        {
            if (res != nullptr)
            {
                res->unload();
                delete res;
            }
        }
        resources.clear();
    }

    void Context::destroyResource(Resource* res) noexcept
    {
        //! get the id from the given resource pointer and find iterator from the resource map with id.
        GoonID id = res->getID();
        resources[id] = nullptr;
        idStack.push(id);
        delete res;
    }
};