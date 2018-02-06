#include "tortoiseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<tortoiseApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

tortoiseApp::tortoiseApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  tortoiseApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  tortoiseApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  tortoiseApp::registerExecFlags(_factory);
}

tortoiseApp::~tortoiseApp() {}

void
tortoiseApp::registerApps()
{
  registerApp(tortoiseApp);
}

void
tortoiseApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
tortoiseApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
tortoiseApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
tortoiseApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
tortoiseApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
tortoiseApp__registerApps()
{
  tortoiseApp::registerApps();
}

extern "C" void
tortoiseApp__registerObjects(Factory & factory)
{
  tortoiseApp::registerObjects(factory);
}

extern "C" void
tortoiseApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  tortoiseApp::associateSyntax(syntax, action_factory);
}

extern "C" void
tortoiseApp__registerExecFlags(Factory & factory)
{
  tortoiseApp::registerExecFlags(factory);
}
