#include "Context.h"

#include "Resource/Resource.h"

namespace gr
{
    template < > gr::Context* Singleton<gr::Context>::instance = nullptr;

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

    template <typename Type>
    Type* Context::getResource(GoonID id) noexcept
    {
        //! get resource pointer with id
        Resource* res = resources[id];
        //! it given pointer matched with id is nullptr, return nullptr
        //! otherwise downcasting to required type
        return res == nullptr ? nullptr : (Type*)(&res);
    }

    template <typename Type, typename... Args>
    Type* Context::generateResource(Args&&... args) noexcept
    {
        //! generate resource with given type which must be a class inherited by Resource class.
        //! And load that resource with it's initialized member variables.
        Resource* res = new Type(std::forward<Args>(args)...);
        res->load();
        //! pop id from the stack which will be used as identification of the resource.
        GoonID id = idStack.top();
        idStack.pop();
        //! insert the pair of id and resource pointer to resource map.
        resources[id] = res;
        return res;
    }

    void Context::destroyResource(Resource* res) noexcept
    {
        //! get the id from the given resource pointer and find iterator from the resource map with id.
        GoonID id = res->getID();
        res->unload();
        delete res;
        resources[id] = nullptr;
        idStack.push(id);
    }
};