/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ExampleInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UExampleInterface : public UInterface
{
  GENERATED_BODY()

  // create a property
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Example")
  FString ExampleProperty;

  // create a function
  UFUNCTION(BlueprintCallable, Category = "Example")
  void ExampleFunction();
};
