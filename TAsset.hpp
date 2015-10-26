#ifndef TASSET_H
#define TASSET_H

#include <string>
#include "TAssetHandler.hpp"
#include "ore_types.hpp"

namespace SQE{
  template<class TYPE>
  class TAsset{
    public:
      TAsset(){} //TODO
      virtual ~TAsset(){
        handler.DropReference(id);
      }

      bool IsLoaded(void) cost{
        return handler.IsLoaded(id);
      }

      const typeAssetID GetID(void) cost{
        return id;
      }

      void SetID(const typeAssetID id){
        this.id = id;
      }

      protected:
        TAssetHandler<TYPE>& handler;
        TYPE* asset;
        typeAssetID id;
  }
}

#endif
