from __future__ import print_function, absolute_import, division  # makes KratosMultiphysics backward compatible with python 2.6 and 2.7

# Importing the Kratos Library
import KratosMultiphysics

# Import applications
import KratosMultiphysics.ConvectionDiffusionApplication as ConvectionDiffusionApplication

# Import base class file
from KratosMultiphysics.ConvectionDiffusionApplication.convection_diffusion_transient_solver import ConvectionDiffusionTransientSolver
import KratosMultiphysics.RomApplication as romapp

def CreateSolver(model, custom_settings):
    return ROMSolver(model, custom_settings)

class ROMSolver(ConvectionDiffusionTransientSolver):
    """The transient class for ROM convection-diffusion solvers.

    See convection_diffusion_transient_solver.py for more information.
    """

    def __init__(self, model, custom_settings):
        KratosMultiphysics.Logger.PrintWarning('\x1b[1;31m[DEPRECATED CLASS] \x1b[0m',"\'convection_diffusion_transient_rom_solver\'", "class is deprecated. Use the generic\'RomSolver\' one instead.")

        super(ROMSolver, self).__init__(model, custom_settings)
        KratosMultiphysics.Logger.PrintInfo("::[ROMSolver]:: ", "Construction finished")

    #### Private functions ####
    @classmethod
    def GetDefaultParameters(cls):
        default_settings = KratosMultiphysics.Parameters("""
        {
            "rom_settings": {
            "nodal_unknowns": [ "TEMPERATURE" ],
            "number_of_rom_dofs": 3
            }
        }
        """)
        default_settings.AddMissingParameters(super(ROMSolver,cls).GetDefaultParameters())
        return default_settings

    def AddVariables(self):
        super(ROMSolver, self).AddVariables() #Adding nodal area variable
        self.main_model_part.AddNodalSolutionStepVariable(KratosMultiphysics.NODAL_AREA)

    def _CreateBuilderAndSolver(self):
        linear_solver = self._GetLinearSolver()
        rom_parameters=self.settings["rom_settings"]
        builder_and_solver = romapp.ROMBuilderAndSolver(linear_solver, rom_parameters)
        return builder_and_solver
