//
//   Project Name:                  KratosDamApplication $
//   Last Modified by:    $Author:    Ignasi de Pouplana $
//   Date:                $Date:           February 2017 $
//   Revision:            $Revision:                 1.0 $
//

#if !defined (KRATOS_THERMAL_SIMO_JU_NONLOCAL_DAMAGE_PLANE_STRAIN_2D_LAW_H_INCLUDED)
#define  KRATOS_THERMAL_SIMO_JU_NONLOCAL_DAMAGE_PLANE_STRAIN_2D_LAW_H_INCLUDED

// System includes
#include <cmath>

// Project includes
#include "includes/serializer.h"

// Application includes
#include "custom_constitutive/thermal_nonlocal_damage_plane_strain_2D_law.hpp"
#include "custom_constitutive/custom_hardening_laws/exponential_damage_hardening_law.hpp"
#include "custom_constitutive/custom_yield_criteria/simo_ju_yield_criterion.hpp"
#include "custom_constitutive/custom_flow_rules/nonlocal_damage_flow_rule.hpp"
#include "dam_application_variables.h"

namespace Kratos
{

class KRATOS_API(DAM_APPLICATION) ThermalSimoJuNonlocalDamagePlaneStrain2DLaw : public ThermalNonlocalDamagePlaneStrain2DLaw
{

public:

    KRATOS_CLASS_POINTER_DEFINITION(ThermalSimoJuNonlocalDamagePlaneStrain2DLaw);

    typedef FlowRule::Pointer FlowRulePointer;
    typedef YieldCriterion::Pointer YieldCriterionPointer;
    typedef HardeningLaw::Pointer HardeningLawPointer;

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    /// Default Constructor
    ThermalSimoJuNonlocalDamagePlaneStrain2DLaw();

    /// Second Constructor
    ThermalSimoJuNonlocalDamagePlaneStrain2DLaw(FlowRulePointer pFlowRule, YieldCriterionPointer pYieldCriterion, HardeningLawPointer pHardeningLaw);

    /// Copy Constructor
    ThermalSimoJuNonlocalDamagePlaneStrain2DLaw (const ThermalSimoJuNonlocalDamagePlaneStrain2DLaw& rOther);

    /// Destructor
    virtual ~ThermalSimoJuNonlocalDamagePlaneStrain2DLaw();

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    int Check(const Properties& rMaterialProperties, const GeometryType& rElementGeometry, const ProcessInfo& rCurrentProcessInfo) const override;

    ConstitutiveLaw::Pointer Clone() const override;

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

protected:

    /// Member Variables

///----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    void CalculateCharacteristicSize( double& rCharacteristicSize, const GeometryType& DomainGeometry ) override;

private:

    /// Serialization

    friend class Serializer;

    void save(Serializer& rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS( rSerializer, ConstitutiveLaw )
    }

    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS( rSerializer, ConstitutiveLaw )
    }

}; // Class ThermalSimoJuNonlocalDamagePlaneStrain2DLaw
}  // namespace Kratos.
#endif // KRATOS_THERMAL_SIMO_JU_NONLOCAL_DAMAGE_PLANE_STRAIN_2D_LAW_H_INCLUDED  defined