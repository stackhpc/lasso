# This file was created automatically by SWIG 1.3.28.
# Don't modify this file, modify the SWIG interface instead.
package lasso;
require Exporter;
require DynaLoader;
@ISA = qw(Exporter DynaLoader);
package lassoc;
bootstrap lasso;
package lasso;
@EXPORT = qw( );

# ---------- BASE METHODS -------------

package lasso;

sub TIEHASH {
    my ($classname,$obj) = @_;
    return bless $obj, $classname;
}

sub CLEAR { }

sub FIRSTKEY { }

sub NEXTKEY { }

sub FETCH {
    my ($self,$field) = @_;
    my $member_func = "swig_${field}_get";
    $self->$member_func();
}

sub STORE {
    my ($self,$field,$newval) = @_;
    my $member_func = "swig_${field}_set";
    $self->$member_func($newval);
}

sub this {
    my $ptr = shift;
    return tied(%$ptr);
}


# ------- FUNCTION WRAPPERS --------

package lasso;

*init = *lassoc::init;
*shutdown = *lassoc::shutdown;
*checkVersion = *lassoc::checkVersion;
*registerDstService = *lassoc::registerDstService;
*getRequestTypeFromSoapMsg = *lassoc::getRequestTypeFromSoapMsg;
*isLibertyQuery = *lassoc::isLibertyQuery;

############# Class : lasso::Node ##############

package lasso::Node;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Node(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Node($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Node_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::NodeList ##############

package lasso::NodeList;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_NodeList(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_NodeList($self);
        delete $OWNER{$self};
    }
}

*append = *lassoc::NodeList_append;
*cast = *lassoc::NodeList_cast;
*frompointer = *lassoc::NodeList_frompointer;
*getItem = *lassoc::NodeList_getItem;
*length = *lassoc::NodeList_length;
*setItem = *lassoc::NodeList_setItem;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::StringList ##############

package lasso::StringList;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_StringList(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_StringList($self);
        delete $OWNER{$self};
    }
}

*append = *lassoc::StringList_append;
*cast = *lassoc::StringList_cast;
*frompointer = *lassoc::StringList_frompointer;
*getItem = *lassoc::StringList_getItem;
*length = *lassoc::StringList_length;
*setItem = *lassoc::StringList_setItem;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAdvice ##############

package lasso::SamlAdvice;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_assertion_get = *lassoc::SamlAdvice_assertion_get;
*swig_assertion_set = *lassoc::SamlAdvice_assertion_set;
*swig_assertionIdReference_get = *lassoc::SamlAdvice_assertionIdReference_get;
*swig_assertionIdReference_set = *lassoc::SamlAdvice_assertionIdReference_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAdvice(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAdvice($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAdvice_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAssertion ##############

package lasso::SamlAssertion;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_assertionId_get = *lassoc::SamlAssertion_assertionId_get;
*swig_assertionId_set = *lassoc::SamlAssertion_assertionId_set;
*swig_certificateFile_get = *lassoc::SamlAssertion_certificateFile_get;
*swig_certificateFile_set = *lassoc::SamlAssertion_certificateFile_set;
*swig_issueInstant_get = *lassoc::SamlAssertion_issueInstant_get;
*swig_issueInstant_set = *lassoc::SamlAssertion_issueInstant_set;
*swig_issuer_get = *lassoc::SamlAssertion_issuer_get;
*swig_issuer_set = *lassoc::SamlAssertion_issuer_set;
*swig_majorVersion_get = *lassoc::SamlAssertion_majorVersion_get;
*swig_majorVersion_set = *lassoc::SamlAssertion_majorVersion_set;
*swig_minorVersion_get = *lassoc::SamlAssertion_minorVersion_get;
*swig_minorVersion_set = *lassoc::SamlAssertion_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::SamlAssertion_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::SamlAssertion_privateKeyFile_set;
*swig_signMethod_get = *lassoc::SamlAssertion_signMethod_get;
*swig_signMethod_set = *lassoc::SamlAssertion_signMethod_set;
*swig_signType_get = *lassoc::SamlAssertion_signType_get;
*swig_signType_set = *lassoc::SamlAssertion_signType_set;
*swig_advice_get = *lassoc::SamlAssertion_advice_get;
*swig_advice_set = *lassoc::SamlAssertion_advice_set;
*swig_attributeStatement_get = *lassoc::SamlAssertion_attributeStatement_get;
*swig_attributeStatement_set = *lassoc::SamlAssertion_attributeStatement_set;
*swig_authenticationStatement_get = *lassoc::SamlAssertion_authenticationStatement_get;
*swig_authenticationStatement_set = *lassoc::SamlAssertion_authenticationStatement_set;
*swig_conditions_get = *lassoc::SamlAssertion_conditions_get;
*swig_conditions_set = *lassoc::SamlAssertion_conditions_set;
*swig_subjectStatement_get = *lassoc::SamlAssertion_subjectStatement_get;
*swig_subjectStatement_set = *lassoc::SamlAssertion_subjectStatement_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAssertion(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAssertion($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAssertion_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAttribute ##############

package lasso::SamlAttribute;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_attributeName_get = *lassoc::SamlAttribute_attributeName_get;
*swig_attributeName_set = *lassoc::SamlAttribute_attributeName_set;
*swig_attributeNamespace_get = *lassoc::SamlAttribute_attributeNamespace_get;
*swig_attributeNamespace_set = *lassoc::SamlAttribute_attributeNamespace_set;
*swig_attributeValue_get = *lassoc::SamlAttribute_attributeValue_get;
*swig_attributeValue_set = *lassoc::SamlAttribute_attributeValue_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAttribute(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAttribute($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAttribute_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAttributeDesignator ##############

package lasso::SamlAttributeDesignator;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_attributeName_get = *lassoc::SamlAttributeDesignator_attributeName_get;
*swig_attributeName_set = *lassoc::SamlAttributeDesignator_attributeName_set;
*swig_attributeNamespace_get = *lassoc::SamlAttributeDesignator_attributeNamespace_get;
*swig_attributeNamespace_set = *lassoc::SamlAttributeDesignator_attributeNamespace_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAttributeDesignator(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAttributeDesignator($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAttributeDesignator_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAttributeStatement ##############

package lasso::SamlAttributeStatement;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_subject_get = *lassoc::SamlAttributeStatement_subject_get;
*swig_subject_set = *lassoc::SamlAttributeStatement_subject_set;
*swig_attribute_get = *lassoc::SamlAttributeStatement_attribute_get;
*swig_attribute_set = *lassoc::SamlAttributeStatement_attribute_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAttributeStatement(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAttributeStatement($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAttributeStatement_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAttributeValue ##############

package lasso::SamlAttributeValue;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_any_get = *lassoc::SamlAttributeValue_any_get;
*swig_any_set = *lassoc::SamlAttributeValue_any_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAttributeValue(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAttributeValue($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAttributeValue_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAudienceRestrictionCondition ##############

package lasso::SamlAudienceRestrictionCondition;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_audience_get = *lassoc::SamlAudienceRestrictionCondition_audience_get;
*swig_audience_set = *lassoc::SamlAudienceRestrictionCondition_audience_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAudienceRestrictionCondition(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAudienceRestrictionCondition($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAudienceRestrictionCondition_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAuthenticationStatement ##############

package lasso::SamlAuthenticationStatement;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_authenticationInstant_get = *lassoc::SamlAuthenticationStatement_authenticationInstant_get;
*swig_authenticationInstant_set = *lassoc::SamlAuthenticationStatement_authenticationInstant_set;
*swig_authenticationMethod_get = *lassoc::SamlAuthenticationStatement_authenticationMethod_get;
*swig_authenticationMethod_set = *lassoc::SamlAuthenticationStatement_authenticationMethod_set;
*swig_authorityBinding_get = *lassoc::SamlAuthenticationStatement_authorityBinding_get;
*swig_authorityBinding_set = *lassoc::SamlAuthenticationStatement_authorityBinding_set;
*swig_subjectLocality_get = *lassoc::SamlAuthenticationStatement_subjectLocality_get;
*swig_subjectLocality_set = *lassoc::SamlAuthenticationStatement_subjectLocality_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAuthenticationStatement(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAuthenticationStatement($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAuthenticationStatement_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlAuthorityBinding ##############

package lasso::SamlAuthorityBinding;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_authorityKind_get = *lassoc::SamlAuthorityBinding_authorityKind_get;
*swig_authorityKind_set = *lassoc::SamlAuthorityBinding_authorityKind_set;
*swig_location_get = *lassoc::SamlAuthorityBinding_location_get;
*swig_location_set = *lassoc::SamlAuthorityBinding_location_set;
*swig_binding_get = *lassoc::SamlAuthorityBinding_binding_get;
*swig_binding_set = *lassoc::SamlAuthorityBinding_binding_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlAuthorityBinding(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlAuthorityBinding($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlAuthorityBinding_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlConditionAbstract ##############

package lasso::SamlConditionAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
*dump = *lassoc::SamlConditionAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlConditions ##############

package lasso::SamlConditions;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_notBefore_get = *lassoc::SamlConditions_notBefore_get;
*swig_notBefore_set = *lassoc::SamlConditions_notBefore_set;
*swig_notOnOrAfter_get = *lassoc::SamlConditions_notOnOrAfter_get;
*swig_notOnOrAfter_set = *lassoc::SamlConditions_notOnOrAfter_set;
*swig_audienceRestrictionCondition_get = *lassoc::SamlConditions_audienceRestrictionCondition_get;
*swig_audienceRestrictionCondition_set = *lassoc::SamlConditions_audienceRestrictionCondition_set;
*swig_condition_get = *lassoc::SamlConditions_condition_get;
*swig_condition_set = *lassoc::SamlConditions_condition_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlConditions(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlConditions($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlConditions_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlNameIdentifier ##############

package lasso::SamlNameIdentifier;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_content_get = *lassoc::SamlNameIdentifier_content_get;
*swig_content_set = *lassoc::SamlNameIdentifier_content_set;
*swig_format_get = *lassoc::SamlNameIdentifier_format_get;
*swig_format_set = *lassoc::SamlNameIdentifier_format_set;
*swig_nameQualifier_get = *lassoc::SamlNameIdentifier_nameQualifier_get;
*swig_nameQualifier_set = *lassoc::SamlNameIdentifier_nameQualifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlNameIdentifier(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlNameIdentifier($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlNameIdentifier_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlStatementAbstract ##############

package lasso::SamlStatementAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
*dump = *lassoc::SamlStatementAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlSubject ##############

package lasso::SamlSubject;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_nameIdentifier_get = *lassoc::SamlSubject_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::SamlSubject_nameIdentifier_set;
*swig_subjectConfirmation_get = *lassoc::SamlSubject_subjectConfirmation_get;
*swig_subjectConfirmation_set = *lassoc::SamlSubject_subjectConfirmation_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlSubject(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlSubject($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlSubject_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlSubjectConfirmation ##############

package lasso::SamlSubjectConfirmation;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_subjectConfirmationData_get = *lassoc::SamlSubjectConfirmation_subjectConfirmationData_get;
*swig_subjectConfirmationData_set = *lassoc::SamlSubjectConfirmation_subjectConfirmationData_set;
*swig_confirmationMethod_get = *lassoc::SamlSubjectConfirmation_confirmationMethod_get;
*swig_confirmationMethod_set = *lassoc::SamlSubjectConfirmation_confirmationMethod_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlSubjectConfirmation(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlSubjectConfirmation($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlSubjectConfirmation_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlSubjectLocality ##############

package lasso::SamlSubjectLocality;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_dnsAddress_get = *lassoc::SamlSubjectLocality_dnsAddress_get;
*swig_dnsAddress_set = *lassoc::SamlSubjectLocality_dnsAddress_set;
*swig_ipAddress_get = *lassoc::SamlSubjectLocality_ipAddress_get;
*swig_ipAddress_set = *lassoc::SamlSubjectLocality_ipAddress_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlSubjectLocality(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlSubjectLocality($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlSubjectLocality_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlSubjectStatement ##############

package lasso::SamlSubjectStatement;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_subject_get = *lassoc::SamlSubjectStatement_subject_get;
*swig_subject_set = *lassoc::SamlSubjectStatement_subject_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlSubjectStatement(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlSubjectStatement($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlSubjectStatement_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlSubjectStatementAbstract ##############

package lasso::SamlSubjectStatementAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_subject_get = *lassoc::SamlSubjectStatementAbstract_subject_get;
*swig_subject_set = *lassoc::SamlSubjectStatementAbstract_subject_set;
*dump = *lassoc::SamlSubjectStatementAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlpRequest ##############

package lasso::SamlpRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_assertionArtifact_get = *lassoc::SamlpRequest_assertionArtifact_get;
*swig_assertionArtifact_set = *lassoc::SamlpRequest_assertionArtifact_set;
*swig_certificateFile_get = *lassoc::SamlpRequest_certificateFile_get;
*swig_certificateFile_set = *lassoc::SamlpRequest_certificateFile_set;
*swig_issueInstant_get = *lassoc::SamlpRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::SamlpRequest_issueInstant_set;
*swig_majorVersion_get = *lassoc::SamlpRequest_majorVersion_get;
*swig_majorVersion_set = *lassoc::SamlpRequest_majorVersion_set;
*swig_minorVersion_get = *lassoc::SamlpRequest_minorVersion_get;
*swig_minorVersion_set = *lassoc::SamlpRequest_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::SamlpRequest_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::SamlpRequest_privateKeyFile_set;
*swig_requestId_get = *lassoc::SamlpRequest_requestId_get;
*swig_requestId_set = *lassoc::SamlpRequest_requestId_set;
*swig_respondWith_get = *lassoc::SamlpRequest_respondWith_get;
*swig_respondWith_set = *lassoc::SamlpRequest_respondWith_set;
*swig_signMethod_get = *lassoc::SamlpRequest_signMethod_get;
*swig_signMethod_set = *lassoc::SamlpRequest_signMethod_set;
*swig_signType_get = *lassoc::SamlpRequest_signType_get;
*swig_signType_set = *lassoc::SamlpRequest_signType_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlpRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlpRequest($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlpRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlpRequestAbstract ##############

package lasso::SamlpRequestAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_certificateFile_get = *lassoc::SamlpRequestAbstract_certificateFile_get;
*swig_certificateFile_set = *lassoc::SamlpRequestAbstract_certificateFile_set;
*swig_issueInstant_get = *lassoc::SamlpRequestAbstract_issueInstant_get;
*swig_issueInstant_set = *lassoc::SamlpRequestAbstract_issueInstant_set;
*swig_majorVersion_get = *lassoc::SamlpRequestAbstract_majorVersion_get;
*swig_majorVersion_set = *lassoc::SamlpRequestAbstract_majorVersion_set;
*swig_minorVersion_get = *lassoc::SamlpRequestAbstract_minorVersion_get;
*swig_minorVersion_set = *lassoc::SamlpRequestAbstract_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::SamlpRequestAbstract_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::SamlpRequestAbstract_privateKeyFile_set;
*swig_requestId_get = *lassoc::SamlpRequestAbstract_requestId_get;
*swig_requestId_set = *lassoc::SamlpRequestAbstract_requestId_set;
*swig_signMethod_get = *lassoc::SamlpRequestAbstract_signMethod_get;
*swig_signMethod_set = *lassoc::SamlpRequestAbstract_signMethod_set;
*swig_signType_get = *lassoc::SamlpRequestAbstract_signType_get;
*swig_signType_set = *lassoc::SamlpRequestAbstract_signType_set;
*swig_respondWith_get = *lassoc::SamlpRequestAbstract_respondWith_get;
*swig_respondWith_set = *lassoc::SamlpRequestAbstract_respondWith_set;
*dump = *lassoc::SamlpRequestAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlpResponse ##############

package lasso::SamlpResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_certificateFile_get = *lassoc::SamlpResponse_certificateFile_get;
*swig_certificateFile_set = *lassoc::SamlpResponse_certificateFile_set;
*swig_inResponseTo_get = *lassoc::SamlpResponse_inResponseTo_get;
*swig_inResponseTo_set = *lassoc::SamlpResponse_inResponseTo_set;
*swig_issueInstant_get = *lassoc::SamlpResponse_issueInstant_get;
*swig_issueInstant_set = *lassoc::SamlpResponse_issueInstant_set;
*swig_majorVersion_get = *lassoc::SamlpResponse_majorVersion_get;
*swig_majorVersion_set = *lassoc::SamlpResponse_majorVersion_set;
*swig_minorVersion_get = *lassoc::SamlpResponse_minorVersion_get;
*swig_minorVersion_set = *lassoc::SamlpResponse_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::SamlpResponse_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::SamlpResponse_privateKeyFile_set;
*swig_recipient_get = *lassoc::SamlpResponse_recipient_get;
*swig_recipient_set = *lassoc::SamlpResponse_recipient_set;
*swig_responseId_get = *lassoc::SamlpResponse_responseId_get;
*swig_responseId_set = *lassoc::SamlpResponse_responseId_set;
*swig_signMethod_get = *lassoc::SamlpResponse_signMethod_get;
*swig_signMethod_set = *lassoc::SamlpResponse_signMethod_set;
*swig_signType_get = *lassoc::SamlpResponse_signType_get;
*swig_signType_set = *lassoc::SamlpResponse_signType_set;
*swig_assertion_get = *lassoc::SamlpResponse_assertion_get;
*swig_assertion_set = *lassoc::SamlpResponse_assertion_set;
*swig_status_get = *lassoc::SamlpResponse_status_get;
*swig_status_set = *lassoc::SamlpResponse_status_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlpResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlpResponse($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlpResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlpResponseAbstract ##############

package lasso::SamlpResponseAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_certificateFile_get = *lassoc::SamlpResponseAbstract_certificateFile_get;
*swig_certificateFile_set = *lassoc::SamlpResponseAbstract_certificateFile_set;
*swig_inResponseTo_get = *lassoc::SamlpResponseAbstract_inResponseTo_get;
*swig_inResponseTo_set = *lassoc::SamlpResponseAbstract_inResponseTo_set;
*swig_issueInstant_get = *lassoc::SamlpResponseAbstract_issueInstant_get;
*swig_issueInstant_set = *lassoc::SamlpResponseAbstract_issueInstant_set;
*swig_majorVersion_get = *lassoc::SamlpResponseAbstract_majorVersion_get;
*swig_majorVersion_set = *lassoc::SamlpResponseAbstract_majorVersion_set;
*swig_minorVersion_get = *lassoc::SamlpResponseAbstract_minorVersion_get;
*swig_minorVersion_set = *lassoc::SamlpResponseAbstract_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::SamlpResponseAbstract_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::SamlpResponseAbstract_privateKeyFile_set;
*swig_recipient_get = *lassoc::SamlpResponseAbstract_recipient_get;
*swig_recipient_set = *lassoc::SamlpResponseAbstract_recipient_set;
*swig_responseId_get = *lassoc::SamlpResponseAbstract_responseId_get;
*swig_responseId_set = *lassoc::SamlpResponseAbstract_responseId_set;
*swig_signMethod_get = *lassoc::SamlpResponseAbstract_signMethod_get;
*swig_signMethod_set = *lassoc::SamlpResponseAbstract_signMethod_set;
*swig_signType_get = *lassoc::SamlpResponseAbstract_signType_get;
*swig_signType_set = *lassoc::SamlpResponseAbstract_signType_set;
*dump = *lassoc::SamlpResponseAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlpStatus ##############

package lasso::SamlpStatus;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_statusMessage_get = *lassoc::SamlpStatus_statusMessage_get;
*swig_statusMessage_set = *lassoc::SamlpStatus_statusMessage_set;
*swig_statusCode_get = *lassoc::SamlpStatus_statusCode_get;
*swig_statusCode_set = *lassoc::SamlpStatus_statusCode_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlpStatus(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlpStatus($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlpStatus_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::SamlpStatusCode ##############

package lasso::SamlpStatusCode;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_value_get = *lassoc::SamlpStatusCode_value_get;
*swig_value_set = *lassoc::SamlpStatusCode_value_set;
*swig_statusCode_get = *lassoc::SamlpStatusCode_statusCode_get;
*swig_statusCode_set = *lassoc::SamlpStatusCode_statusCode_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_SamlpStatusCode(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_SamlpStatusCode($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::SamlpStatusCode_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibAssertion ##############

package lasso::LibAssertion;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_advice_get = *lassoc::LibAssertion_advice_get;
*swig_advice_set = *lassoc::LibAssertion_advice_set;
*swig_assertionId_get = *lassoc::LibAssertion_assertionId_get;
*swig_assertionId_set = *lassoc::LibAssertion_assertionId_set;
*swig_attributeStatement_get = *lassoc::LibAssertion_attributeStatement_get;
*swig_attributeStatement_set = *lassoc::LibAssertion_attributeStatement_set;
*swig_authenticationStatement_get = *lassoc::LibAssertion_authenticationStatement_get;
*swig_authenticationStatement_set = *lassoc::LibAssertion_authenticationStatement_set;
*swig_certificateFile_get = *lassoc::LibAssertion_certificateFile_get;
*swig_certificateFile_set = *lassoc::LibAssertion_certificateFile_set;
*swig_conditions_get = *lassoc::LibAssertion_conditions_get;
*swig_conditions_set = *lassoc::LibAssertion_conditions_set;
*swig_issueInstant_get = *lassoc::LibAssertion_issueInstant_get;
*swig_issueInstant_set = *lassoc::LibAssertion_issueInstant_set;
*swig_issuer_get = *lassoc::LibAssertion_issuer_get;
*swig_issuer_set = *lassoc::LibAssertion_issuer_set;
*swig_majorVersion_get = *lassoc::LibAssertion_majorVersion_get;
*swig_majorVersion_set = *lassoc::LibAssertion_majorVersion_set;
*swig_minorVersion_get = *lassoc::LibAssertion_minorVersion_get;
*swig_minorVersion_set = *lassoc::LibAssertion_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::LibAssertion_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::LibAssertion_privateKeyFile_set;
*swig_signMethod_get = *lassoc::LibAssertion_signMethod_get;
*swig_signMethod_set = *lassoc::LibAssertion_signMethod_set;
*swig_signType_get = *lassoc::LibAssertion_signType_get;
*swig_signType_set = *lassoc::LibAssertion_signType_set;
*swig_subjectStatement_get = *lassoc::LibAssertion_subjectStatement_get;
*swig_subjectStatement_set = *lassoc::LibAssertion_subjectStatement_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibAssertion(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibAssertion($self);
        delete $OWNER{$self};
    }
}

*newFull = *lassoc::LibAssertion_newFull;
*dump = *lassoc::LibAssertion_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibAuthnRequest ##############

package lasso::LibAuthnRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_affiliationId_get = *lassoc::LibAuthnRequest_affiliationId_get;
*swig_affiliationId_set = *lassoc::LibAuthnRequest_affiliationId_set;
*swig_assertionConsumerServiceId_get = *lassoc::LibAuthnRequest_assertionConsumerServiceId_get;
*swig_assertionConsumerServiceId_set = *lassoc::LibAuthnRequest_assertionConsumerServiceId_set;
*swig_consent_get = *lassoc::LibAuthnRequest_consent_get;
*swig_consent_set = *lassoc::LibAuthnRequest_consent_set;
*swig_forceAuthn_get = *lassoc::LibAuthnRequest_forceAuthn_get;
*swig_forceAuthn_set = *lassoc::LibAuthnRequest_forceAuthn_set;
*swig_isPassive_get = *lassoc::LibAuthnRequest_isPassive_get;
*swig_isPassive_set = *lassoc::LibAuthnRequest_isPassive_set;
*swig_nameIdPolicy_get = *lassoc::LibAuthnRequest_nameIdPolicy_get;
*swig_nameIdPolicy_set = *lassoc::LibAuthnRequest_nameIdPolicy_set;
*swig_protocolProfile_get = *lassoc::LibAuthnRequest_protocolProfile_get;
*swig_protocolProfile_set = *lassoc::LibAuthnRequest_protocolProfile_set;
*swig_providerId_get = *lassoc::LibAuthnRequest_providerId_get;
*swig_providerId_set = *lassoc::LibAuthnRequest_providerId_set;
*swig_relayState_get = *lassoc::LibAuthnRequest_relayState_get;
*swig_relayState_set = *lassoc::LibAuthnRequest_relayState_set;
*swig_certificateFile_get = *lassoc::LibAuthnRequest_certificateFile_get;
*swig_certificateFile_set = *lassoc::LibAuthnRequest_certificateFile_set;
*swig_issueInstant_get = *lassoc::LibAuthnRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::LibAuthnRequest_issueInstant_set;
*swig_majorVersion_get = *lassoc::LibAuthnRequest_majorVersion_get;
*swig_majorVersion_set = *lassoc::LibAuthnRequest_majorVersion_set;
*swig_minorVersion_get = *lassoc::LibAuthnRequest_minorVersion_get;
*swig_minorVersion_set = *lassoc::LibAuthnRequest_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::LibAuthnRequest_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::LibAuthnRequest_privateKeyFile_set;
*swig_requestId_get = *lassoc::LibAuthnRequest_requestId_get;
*swig_requestId_set = *lassoc::LibAuthnRequest_requestId_set;
*swig_respondWith_get = *lassoc::LibAuthnRequest_respondWith_get;
*swig_respondWith_set = *lassoc::LibAuthnRequest_respondWith_set;
*swig_signMethod_get = *lassoc::LibAuthnRequest_signMethod_get;
*swig_signMethod_set = *lassoc::LibAuthnRequest_signMethod_set;
*swig_signType_get = *lassoc::LibAuthnRequest_signType_get;
*swig_signType_set = *lassoc::LibAuthnRequest_signType_set;
*swig_extension_get = *lassoc::LibAuthnRequest_extension_get;
*swig_extension_set = *lassoc::LibAuthnRequest_extension_set;
*swig_requestAuthnContext_get = *lassoc::LibAuthnRequest_requestAuthnContext_get;
*swig_requestAuthnContext_set = *lassoc::LibAuthnRequest_requestAuthnContext_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibAuthnRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibAuthnRequest($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::LibAuthnRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibAuthnResponse ##############

package lasso::LibAuthnResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_consent_get = *lassoc::LibAuthnResponse_consent_get;
*swig_consent_set = *lassoc::LibAuthnResponse_consent_set;
*swig_providerId_get = *lassoc::LibAuthnResponse_providerId_get;
*swig_providerId_set = *lassoc::LibAuthnResponse_providerId_set;
*swig_relayState_get = *lassoc::LibAuthnResponse_relayState_get;
*swig_relayState_set = *lassoc::LibAuthnResponse_relayState_set;
*swig_extension_get = *lassoc::LibAuthnResponse_extension_get;
*swig_extension_set = *lassoc::LibAuthnResponse_extension_set;
*swig_status_get = *lassoc::LibAuthnResponse_status_get;
*swig_status_set = *lassoc::LibAuthnResponse_status_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibAuthnResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibAuthnResponse($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::LibAuthnResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibFederationTerminationNotification ##############

package lasso::LibFederationTerminationNotification;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_consent_get = *lassoc::LibFederationTerminationNotification_consent_get;
*swig_consent_set = *lassoc::LibFederationTerminationNotification_consent_set;
*swig_providerId_get = *lassoc::LibFederationTerminationNotification_providerId_get;
*swig_providerId_set = *lassoc::LibFederationTerminationNotification_providerId_set;
*swig_relayState_get = *lassoc::LibFederationTerminationNotification_relayState_get;
*swig_relayState_set = *lassoc::LibFederationTerminationNotification_relayState_set;
*swig_certificateFile_get = *lassoc::LibFederationTerminationNotification_certificateFile_get;
*swig_certificateFile_set = *lassoc::LibFederationTerminationNotification_certificateFile_set;
*swig_issueInstant_get = *lassoc::LibFederationTerminationNotification_issueInstant_get;
*swig_issueInstant_set = *lassoc::LibFederationTerminationNotification_issueInstant_set;
*swig_majorVersion_get = *lassoc::LibFederationTerminationNotification_majorVersion_get;
*swig_majorVersion_set = *lassoc::LibFederationTerminationNotification_majorVersion_set;
*swig_minorVersion_get = *lassoc::LibFederationTerminationNotification_minorVersion_get;
*swig_minorVersion_set = *lassoc::LibFederationTerminationNotification_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::LibFederationTerminationNotification_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::LibFederationTerminationNotification_privateKeyFile_set;
*swig_requestId_get = *lassoc::LibFederationTerminationNotification_requestId_get;
*swig_requestId_set = *lassoc::LibFederationTerminationNotification_requestId_set;
*swig_respondWith_get = *lassoc::LibFederationTerminationNotification_respondWith_get;
*swig_respondWith_set = *lassoc::LibFederationTerminationNotification_respondWith_set;
*swig_signMethod_get = *lassoc::LibFederationTerminationNotification_signMethod_get;
*swig_signMethod_set = *lassoc::LibFederationTerminationNotification_signMethod_set;
*swig_signType_get = *lassoc::LibFederationTerminationNotification_signType_get;
*swig_signType_set = *lassoc::LibFederationTerminationNotification_signType_set;
*swig_extension_get = *lassoc::LibFederationTerminationNotification_extension_get;
*swig_extension_set = *lassoc::LibFederationTerminationNotification_extension_set;
*swig_nameIdentifier_get = *lassoc::LibFederationTerminationNotification_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::LibFederationTerminationNotification_nameIdentifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibFederationTerminationNotification(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibFederationTerminationNotification($self);
        delete $OWNER{$self};
    }
}

*newFull = *lassoc::LibFederationTerminationNotification_newFull;
*dump = *lassoc::LibFederationTerminationNotification_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibLogoutRequest ##############

package lasso::LibLogoutRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_consent_get = *lassoc::LibLogoutRequest_consent_get;
*swig_consent_set = *lassoc::LibLogoutRequest_consent_set;
*swig_notOnOrAfter_get = *lassoc::LibLogoutRequest_notOnOrAfter_get;
*swig_notOnOrAfter_set = *lassoc::LibLogoutRequest_notOnOrAfter_set;
*swig_providerId_get = *lassoc::LibLogoutRequest_providerId_get;
*swig_providerId_set = *lassoc::LibLogoutRequest_providerId_set;
*swig_relayState_get = *lassoc::LibLogoutRequest_relayState_get;
*swig_relayState_set = *lassoc::LibLogoutRequest_relayState_set;
*swig_sessionIndex_get = *lassoc::LibLogoutRequest_sessionIndex_get;
*swig_sessionIndex_set = *lassoc::LibLogoutRequest_sessionIndex_set;
*swig_certificateFile_get = *lassoc::LibLogoutRequest_certificateFile_get;
*swig_certificateFile_set = *lassoc::LibLogoutRequest_certificateFile_set;
*swig_issueInstant_get = *lassoc::LibLogoutRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::LibLogoutRequest_issueInstant_set;
*swig_majorVersion_get = *lassoc::LibLogoutRequest_majorVersion_get;
*swig_majorVersion_set = *lassoc::LibLogoutRequest_majorVersion_set;
*swig_minorVersion_get = *lassoc::LibLogoutRequest_minorVersion_get;
*swig_minorVersion_set = *lassoc::LibLogoutRequest_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::LibLogoutRequest_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::LibLogoutRequest_privateKeyFile_set;
*swig_requestId_get = *lassoc::LibLogoutRequest_requestId_get;
*swig_requestId_set = *lassoc::LibLogoutRequest_requestId_set;
*swig_respondWith_get = *lassoc::LibLogoutRequest_respondWith_get;
*swig_respondWith_set = *lassoc::LibLogoutRequest_respondWith_set;
*swig_signMethod_get = *lassoc::LibLogoutRequest_signMethod_get;
*swig_signMethod_set = *lassoc::LibLogoutRequest_signMethod_set;
*swig_signType_get = *lassoc::LibLogoutRequest_signType_get;
*swig_signType_set = *lassoc::LibLogoutRequest_signType_set;
*swig_extension_get = *lassoc::LibLogoutRequest_extension_get;
*swig_extension_set = *lassoc::LibLogoutRequest_extension_set;
*swig_nameIdentifier_get = *lassoc::LibLogoutRequest_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::LibLogoutRequest_nameIdentifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibLogoutRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibLogoutRequest($self);
        delete $OWNER{$self};
    }
}

*newFull = *lassoc::LibLogoutRequest_newFull;
*dump = *lassoc::LibLogoutRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibLogoutResponse ##############

package lasso::LibLogoutResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_extension_get = *lassoc::LibLogoutResponse_extension_get;
*swig_extension_set = *lassoc::LibLogoutResponse_extension_set;
*swig_providerId_get = *lassoc::LibLogoutResponse_providerId_get;
*swig_providerId_set = *lassoc::LibLogoutResponse_providerId_set;
*swig_relayState_get = *lassoc::LibLogoutResponse_relayState_get;
*swig_relayState_set = *lassoc::LibLogoutResponse_relayState_set;
*swig_status_get = *lassoc::LibLogoutResponse_status_get;
*swig_status_set = *lassoc::LibLogoutResponse_status_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibLogoutResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibLogoutResponse($self);
        delete $OWNER{$self};
    }
}

*newFull = *lassoc::LibLogoutResponse_newFull;
*dump = *lassoc::LibLogoutResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibRegisterNameIdentifierRequest ##############

package lasso::LibRegisterNameIdentifierRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_providerId_get = *lassoc::LibRegisterNameIdentifierRequest_providerId_get;
*swig_providerId_set = *lassoc::LibRegisterNameIdentifierRequest_providerId_set;
*swig_relayState_get = *lassoc::LibRegisterNameIdentifierRequest_relayState_get;
*swig_relayState_set = *lassoc::LibRegisterNameIdentifierRequest_relayState_set;
*swig_certificateFile_get = *lassoc::LibRegisterNameIdentifierRequest_certificateFile_get;
*swig_certificateFile_set = *lassoc::LibRegisterNameIdentifierRequest_certificateFile_set;
*swig_issueInstant_get = *lassoc::LibRegisterNameIdentifierRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::LibRegisterNameIdentifierRequest_issueInstant_set;
*swig_majorVersion_get = *lassoc::LibRegisterNameIdentifierRequest_majorVersion_get;
*swig_majorVersion_set = *lassoc::LibRegisterNameIdentifierRequest_majorVersion_set;
*swig_minorVersion_get = *lassoc::LibRegisterNameIdentifierRequest_minorVersion_get;
*swig_minorVersion_set = *lassoc::LibRegisterNameIdentifierRequest_minorVersion_set;
*swig_privateKeyFile_get = *lassoc::LibRegisterNameIdentifierRequest_privateKeyFile_get;
*swig_privateKeyFile_set = *lassoc::LibRegisterNameIdentifierRequest_privateKeyFile_set;
*swig_requestId_get = *lassoc::LibRegisterNameIdentifierRequest_requestId_get;
*swig_requestId_set = *lassoc::LibRegisterNameIdentifierRequest_requestId_set;
*swig_respondWith_get = *lassoc::LibRegisterNameIdentifierRequest_respondWith_get;
*swig_respondWith_set = *lassoc::LibRegisterNameIdentifierRequest_respondWith_set;
*swig_signMethod_get = *lassoc::LibRegisterNameIdentifierRequest_signMethod_get;
*swig_signMethod_set = *lassoc::LibRegisterNameIdentifierRequest_signMethod_set;
*swig_signType_get = *lassoc::LibRegisterNameIdentifierRequest_signType_get;
*swig_signType_set = *lassoc::LibRegisterNameIdentifierRequest_signType_set;
*swig_extension_get = *lassoc::LibRegisterNameIdentifierRequest_extension_get;
*swig_extension_set = *lassoc::LibRegisterNameIdentifierRequest_extension_set;
*swig_idpProvidedNameIdentifier_get = *lassoc::LibRegisterNameIdentifierRequest_idpProvidedNameIdentifier_get;
*swig_idpProvidedNameIdentifier_set = *lassoc::LibRegisterNameIdentifierRequest_idpProvidedNameIdentifier_set;
*swig_oldProvidedNameIdentifier_get = *lassoc::LibRegisterNameIdentifierRequest_oldProvidedNameIdentifier_get;
*swig_oldProvidedNameIdentifier_set = *lassoc::LibRegisterNameIdentifierRequest_oldProvidedNameIdentifier_set;
*swig_spProvidedNameIdentifier_get = *lassoc::LibRegisterNameIdentifierRequest_spProvidedNameIdentifier_get;
*swig_spProvidedNameIdentifier_set = *lassoc::LibRegisterNameIdentifierRequest_spProvidedNameIdentifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibRegisterNameIdentifierRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibRegisterNameIdentifierRequest($self);
        delete $OWNER{$self};
    }
}

*newFull = *lassoc::LibRegisterNameIdentifierRequest_newFull;
*dump = *lassoc::LibRegisterNameIdentifierRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibRegisterNameIdentifierResponse ##############

package lasso::LibRegisterNameIdentifierResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_extension_get = *lassoc::LibRegisterNameIdentifierResponse_extension_get;
*swig_extension_set = *lassoc::LibRegisterNameIdentifierResponse_extension_set;
*swig_providerId_get = *lassoc::LibRegisterNameIdentifierResponse_providerId_get;
*swig_providerId_set = *lassoc::LibRegisterNameIdentifierResponse_providerId_set;
*swig_relayState_get = *lassoc::LibRegisterNameIdentifierResponse_relayState_get;
*swig_relayState_set = *lassoc::LibRegisterNameIdentifierResponse_relayState_set;
*swig_status_get = *lassoc::LibRegisterNameIdentifierResponse_status_get;
*swig_status_set = *lassoc::LibRegisterNameIdentifierResponse_status_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibRegisterNameIdentifierResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibRegisterNameIdentifierResponse($self);
        delete $OWNER{$self};
    }
}

*newFull = *lassoc::LibRegisterNameIdentifierResponse_newFull;
*dump = *lassoc::LibRegisterNameIdentifierResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibRequestAuthnContext ##############

package lasso::LibRequestAuthnContext;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_authnContextComparison_get = *lassoc::LibRequestAuthnContext_authnContextComparison_get;
*swig_authnContextComparison_set = *lassoc::LibRequestAuthnContext_authnContextComparison_set;
*swig_authnContextClassRef_get = *lassoc::LibRequestAuthnContext_authnContextClassRef_get;
*swig_authnContextClassRef_set = *lassoc::LibRequestAuthnContext_authnContextClassRef_set;
*swig_authnContextStatementRef_get = *lassoc::LibRequestAuthnContext_authnContextStatementRef_get;
*swig_authnContextStatementRef_set = *lassoc::LibRequestAuthnContext_authnContextStatementRef_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibRequestAuthnContext(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibRequestAuthnContext($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::LibRequestAuthnContext_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::LibStatusResponse ##############

package lasso::LibStatusResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_providerId_get = *lassoc::LibStatusResponse_providerId_get;
*swig_providerId_set = *lassoc::LibStatusResponse_providerId_set;
*swig_relayState_get = *lassoc::LibStatusResponse_relayState_get;
*swig_relayState_set = *lassoc::LibStatusResponse_relayState_set;
*swig_extension_get = *lassoc::LibStatusResponse_extension_get;
*swig_extension_set = *lassoc::LibStatusResponse_extension_set;
*swig_status_get = *lassoc::LibStatusResponse_status_get;
*swig_status_set = *lassoc::LibStatusResponse_status_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_LibStatusResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_LibStatusResponse($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::LibStatusResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Provider ##############

package lasso::Provider;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_caCertChain_get = *lassoc::Provider_caCertChain_get;
*swig_caCertChain_set = *lassoc::Provider_caCertChain_set;
*swig_metadataFilename_get = *lassoc::Provider_metadataFilename_get;
*swig_metadataFilename_set = *lassoc::Provider_metadataFilename_set;
*swig_providerId_get = *lassoc::Provider_providerId_get;
*swig_providerId_set = *lassoc::Provider_providerId_set;
*swig_publicKey_get = *lassoc::Provider_publicKey_get;
*swig_publicKey_set = *lassoc::Provider_publicKey_set;
*swig_role_get = *lassoc::Provider_role_get;
*swig_role_set = *lassoc::Provider_role_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Provider(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Provider($self);
        delete $OWNER{$self};
    }
}

*newFromDump = *lassoc::Provider_newFromDump;
*dump = *lassoc::Provider_dump;
*acceptHttpMethod = *lassoc::Provider_acceptHttpMethod;
*getAssertionConsumerServiceUrl = *lassoc::Provider_getAssertionConsumerServiceUrl;
*getBase64SuccinctId = *lassoc::Provider_getBase64SuccinctId;
*getOrganization = *lassoc::Provider_getOrganization;
*getFirstHttpMethod = *lassoc::Provider_getFirstHttpMethod;
*getMetadataOne = *lassoc::Provider_getMetadataOne;
*hasProtocolProfile = *lassoc::Provider_hasProtocolProfile;
*getProtocolConformance = *lassoc::Provider_getProtocolConformance;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Server ##############

package lasso::Server;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_certificate_get = *lassoc::Server_certificate_get;
*swig_certificate_set = *lassoc::Server_certificate_set;
*swig_privateKey_get = *lassoc::Server_privateKey_get;
*swig_privateKey_set = *lassoc::Server_privateKey_set;
*swig_privateKeyPassword_get = *lassoc::Server_privateKeyPassword_get;
*swig_privateKeyPassword_set = *lassoc::Server_privateKeyPassword_set;
*swig_signatureMethod_get = *lassoc::Server_signatureMethod_get;
*swig_signatureMethod_set = *lassoc::Server_signatureMethod_set;
*swig_caCertChain_get = *lassoc::Server_caCertChain_get;
*swig_caCertChain_set = *lassoc::Server_caCertChain_set;
*swig_metadataFilename_get = *lassoc::Server_metadataFilename_get;
*swig_metadataFilename_set = *lassoc::Server_metadataFilename_set;
*swig_providerId_get = *lassoc::Server_providerId_get;
*swig_providerId_set = *lassoc::Server_providerId_set;
*swig_publicKey_get = *lassoc::Server_publicKey_get;
*swig_publicKey_set = *lassoc::Server_publicKey_set;
*swig_role_get = *lassoc::Server_role_get;
*swig_role_set = *lassoc::Server_role_set;
*swig_providerIds_get = *lassoc::Server_providerIds_get;
*swig_providerIds_set = *lassoc::Server_providerIds_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Server(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Server($self);
        delete $OWNER{$self};
    }
}

*newFromDump = *lassoc::Server_newFromDump;
*acceptHttpMethod = *lassoc::Server_acceptHttpMethod;
*getAssertionConsumerServiceUrl = *lassoc::Server_getAssertionConsumerServiceUrl;
*getBase64SuccinctId = *lassoc::Server_getBase64SuccinctId;
*getOrganization = *lassoc::Server_getOrganization;
*getFirstHttpMethod = *lassoc::Server_getFirstHttpMethod;
*getMetadataOne = *lassoc::Server_getMetadataOne;
*hasProtocolProfile = *lassoc::Server_hasProtocolProfile;
*getProtocolConformance = *lassoc::Server_getProtocolConformance;
*addProvider = *lassoc::Server_addProvider;
*dump = *lassoc::Server_dump;
*getProvider = *lassoc::Server_getProvider;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Federation ##############

package lasso::Federation;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_remoteProviderId_get = *lassoc::Federation_remoteProviderId_get;
*swig_remoteProviderId_set = *lassoc::Federation_remoteProviderId_set;
*swig_localNameIdentifier_get = *lassoc::Federation_localNameIdentifier_get;
*swig_localNameIdentifier_set = *lassoc::Federation_localNameIdentifier_set;
*swig_remoteNameIdentifier_get = *lassoc::Federation_remoteNameIdentifier_get;
*swig_remoteNameIdentifier_set = *lassoc::Federation_remoteNameIdentifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Federation(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Federation($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Federation_dump;
*buildLocalNameIdentifier = *lassoc::Federation_buildLocalNameIdentifier;
*verifyNameIdentifier = *lassoc::Federation_verifyNameIdentifier;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Identity ##############

package lasso::Identity;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_isDirty_get = *lassoc::Identity_isDirty_get;
*swig_isDirty_set = *lassoc::Identity_isDirty_set;
*swig_providerIds_get = *lassoc::Identity_providerIds_get;
*swig_providerIds_set = *lassoc::Identity_providerIds_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Identity(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Identity($self);
        delete $OWNER{$self};
    }
}

*newFromDump = *lassoc::Identity_newFromDump;
*dump = *lassoc::Identity_dump;
*getFederation = *lassoc::Identity_getFederation;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Session ##############

package lasso::Session;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_isDirty_get = *lassoc::Session_isDirty_get;
*swig_isDirty_set = *lassoc::Session_isDirty_set;
*swig_providerIds_get = *lassoc::Session_providerIds_get;
*swig_providerIds_set = *lassoc::Session_providerIds_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Session(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Session($self);
        delete $OWNER{$self};
    }
}

*newFromDump = *lassoc::Session_newFromDump;
*dump = *lassoc::Session_dump;
*getAssertions = *lassoc::Session_getAssertions;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Defederation ##############

package lasso::Defederation;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_artifact_get = *lassoc::Defederation_artifact_get;
*swig_artifact_set = *lassoc::Defederation_artifact_set;
*swig_artifactMessage_get = *lassoc::Defederation_artifactMessage_get;
*swig_artifactMessage_set = *lassoc::Defederation_artifactMessage_set;
*swig_identity_get = *lassoc::Defederation_identity_get;
*swig_identity_set = *lassoc::Defederation_identity_set;
*swig_isIdentityDirty_get = *lassoc::Defederation_isIdentityDirty_get;
*swig_isIdentityDirty_set = *lassoc::Defederation_isIdentityDirty_set;
*swig_isSessionDirty_get = *lassoc::Defederation_isSessionDirty_get;
*swig_isSessionDirty_set = *lassoc::Defederation_isSessionDirty_set;
*swig_msgBody_get = *lassoc::Defederation_msgBody_get;
*swig_msgBody_set = *lassoc::Defederation_msgBody_set;
*swig_msgRelayState_get = *lassoc::Defederation_msgRelayState_get;
*swig_msgRelayState_set = *lassoc::Defederation_msgRelayState_set;
*swig_msgUrl_get = *lassoc::Defederation_msgUrl_get;
*swig_msgUrl_set = *lassoc::Defederation_msgUrl_set;
*swig_nameIdentifier_get = *lassoc::Defederation_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::Defederation_nameIdentifier_set;
*swig_remoteProviderId_get = *lassoc::Defederation_remoteProviderId_get;
*swig_remoteProviderId_set = *lassoc::Defederation_remoteProviderId_set;
*swig_request_get = *lassoc::Defederation_request_get;
*swig_request_set = *lassoc::Defederation_request_set;
*swig_response_get = *lassoc::Defederation_response_get;
*swig_response_set = *lassoc::Defederation_response_set;
*swig_server_get = *lassoc::Defederation_server_get;
*swig_server_set = *lassoc::Defederation_server_set;
*swig_session_get = *lassoc::Defederation_session_get;
*swig_session_set = *lassoc::Defederation_session_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Defederation(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Defederation($self);
        delete $OWNER{$self};
    }
}

*setIdentityFromDump = *lassoc::Defederation_setIdentityFromDump;
*setSessionFromDump = *lassoc::Defederation_setSessionFromDump;
*buildNotificationMsg = *lassoc::Defederation_buildNotificationMsg;
*initNotification = *lassoc::Defederation_initNotification;
*processNotificationMsg = *lassoc::Defederation_processNotificationMsg;
*validateNotification = *lassoc::Defederation_validateNotification;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Login ##############

package lasso::Login;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_assertionArtifact_get = *lassoc::Login_assertionArtifact_get;
*swig_assertionArtifact_set = *lassoc::Login_assertionArtifact_set;
*swig_protocolProfile_get = *lassoc::Login_protocolProfile_get;
*swig_protocolProfile_set = *lassoc::Login_protocolProfile_set;
*swig_artifact_get = *lassoc::Login_artifact_get;
*swig_artifact_set = *lassoc::Login_artifact_set;
*swig_artifactMessage_get = *lassoc::Login_artifactMessage_get;
*swig_artifactMessage_set = *lassoc::Login_artifactMessage_set;
*swig_identity_get = *lassoc::Login_identity_get;
*swig_identity_set = *lassoc::Login_identity_set;
*swig_isIdentityDirty_get = *lassoc::Login_isIdentityDirty_get;
*swig_isIdentityDirty_set = *lassoc::Login_isIdentityDirty_set;
*swig_isSessionDirty_get = *lassoc::Login_isSessionDirty_get;
*swig_isSessionDirty_set = *lassoc::Login_isSessionDirty_set;
*swig_msgBody_get = *lassoc::Login_msgBody_get;
*swig_msgBody_set = *lassoc::Login_msgBody_set;
*swig_msgRelayState_get = *lassoc::Login_msgRelayState_get;
*swig_msgRelayState_set = *lassoc::Login_msgRelayState_set;
*swig_msgUrl_get = *lassoc::Login_msgUrl_get;
*swig_msgUrl_set = *lassoc::Login_msgUrl_set;
*swig_nameIdentifier_get = *lassoc::Login_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::Login_nameIdentifier_set;
*swig_remoteProviderId_get = *lassoc::Login_remoteProviderId_get;
*swig_remoteProviderId_set = *lassoc::Login_remoteProviderId_set;
*swig_request_get = *lassoc::Login_request_get;
*swig_request_set = *lassoc::Login_request_set;
*swig_response_get = *lassoc::Login_response_get;
*swig_response_set = *lassoc::Login_response_set;
*swig_server_get = *lassoc::Login_server_get;
*swig_server_set = *lassoc::Login_server_set;
*swig_session_get = *lassoc::Login_session_get;
*swig_session_set = *lassoc::Login_session_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Login(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Login($self);
        delete $OWNER{$self};
    }
}

*newFromDump = *lassoc::Login_newFromDump;
*setIdentityFromDump = *lassoc::Login_setIdentityFromDump;
*setSessionFromDump = *lassoc::Login_setSessionFromDump;
*acceptSso = *lassoc::Login_acceptSso;
*buildArtifactMsg = *lassoc::Login_buildArtifactMsg;
*buildAssertion = *lassoc::Login_buildAssertion;
*buildAuthnRequestMsg = *lassoc::Login_buildAuthnRequestMsg;
*buildAuthnResponseMsg = *lassoc::Login_buildAuthnResponseMsg;
*buildRequestMsg = *lassoc::Login_buildRequestMsg;
*buildResponseMsg = *lassoc::Login_buildResponseMsg;
*dump = *lassoc::Login_dump;
*initAuthnRequest = *lassoc::Login_initAuthnRequest;
*initRequest = *lassoc::Login_initRequest;
*initIdpInitiatedAuthnRequest = *lassoc::Login_initIdpInitiatedAuthnRequest;
*mustAskForConsent = *lassoc::Login_mustAskForConsent;
*mustAuthenticate = *lassoc::Login_mustAuthenticate;
*processAuthnRequestMsg = *lassoc::Login_processAuthnRequestMsg;
*processAuthnResponseMsg = *lassoc::Login_processAuthnResponseMsg;
*processRequestMsg = *lassoc::Login_processRequestMsg;
*processResponseMsg = *lassoc::Login_processResponseMsg;
*setResourceId = *lassoc::Login_setResourceId;
*validateRequestMsg = *lassoc::Login_validateRequestMsg;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Logout ##############

package lasso::Logout;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_artifact_get = *lassoc::Logout_artifact_get;
*swig_artifact_set = *lassoc::Logout_artifact_set;
*swig_artifactMessage_get = *lassoc::Logout_artifactMessage_get;
*swig_artifactMessage_set = *lassoc::Logout_artifactMessage_set;
*swig_identity_get = *lassoc::Logout_identity_get;
*swig_identity_set = *lassoc::Logout_identity_set;
*swig_isIdentityDirty_get = *lassoc::Logout_isIdentityDirty_get;
*swig_isIdentityDirty_set = *lassoc::Logout_isIdentityDirty_set;
*swig_isSessionDirty_get = *lassoc::Logout_isSessionDirty_get;
*swig_isSessionDirty_set = *lassoc::Logout_isSessionDirty_set;
*swig_msgBody_get = *lassoc::Logout_msgBody_get;
*swig_msgBody_set = *lassoc::Logout_msgBody_set;
*swig_msgRelayState_get = *lassoc::Logout_msgRelayState_get;
*swig_msgRelayState_set = *lassoc::Logout_msgRelayState_set;
*swig_msgUrl_get = *lassoc::Logout_msgUrl_get;
*swig_msgUrl_set = *lassoc::Logout_msgUrl_set;
*swig_nameIdentifier_get = *lassoc::Logout_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::Logout_nameIdentifier_set;
*swig_remoteProviderId_get = *lassoc::Logout_remoteProviderId_get;
*swig_remoteProviderId_set = *lassoc::Logout_remoteProviderId_set;
*swig_request_get = *lassoc::Logout_request_get;
*swig_request_set = *lassoc::Logout_request_set;
*swig_response_get = *lassoc::Logout_response_get;
*swig_response_set = *lassoc::Logout_response_set;
*swig_server_get = *lassoc::Logout_server_get;
*swig_server_set = *lassoc::Logout_server_set;
*swig_session_get = *lassoc::Logout_session_get;
*swig_session_set = *lassoc::Logout_session_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Logout(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Logout($self);
        delete $OWNER{$self};
    }
}

*newFromDump = *lassoc::Logout_newFromDump;
*setIdentityFromDump = *lassoc::Logout_setIdentityFromDump;
*setSessionFromDump = *lassoc::Logout_setSessionFromDump;
*buildRequestMsg = *lassoc::Logout_buildRequestMsg;
*buildResponseMsg = *lassoc::Logout_buildResponseMsg;
*dump = *lassoc::Logout_dump;
*getNextProviderId = *lassoc::Logout_getNextProviderId;
*initRequest = *lassoc::Logout_initRequest;
*processRequestMsg = *lassoc::Logout_processRequestMsg;
*processResponseMsg = *lassoc::Logout_processResponseMsg;
*resetProviderIdIndex = *lassoc::Logout_resetProviderIdIndex;
*validateRequest = *lassoc::Logout_validateRequest;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Lecp ##############

package lasso::Lecp;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_artifact_get = *lassoc::Lecp_artifact_get;
*swig_artifact_set = *lassoc::Lecp_artifact_set;
*swig_artifactMessage_get = *lassoc::Lecp_artifactMessage_get;
*swig_artifactMessage_set = *lassoc::Lecp_artifactMessage_set;
*swig_identity_get = *lassoc::Lecp_identity_get;
*swig_identity_set = *lassoc::Lecp_identity_set;
*swig_isIdentityDirty_get = *lassoc::Lecp_isIdentityDirty_get;
*swig_isIdentityDirty_set = *lassoc::Lecp_isIdentityDirty_set;
*swig_isSessionDirty_get = *lassoc::Lecp_isSessionDirty_get;
*swig_isSessionDirty_set = *lassoc::Lecp_isSessionDirty_set;
*swig_msgBody_get = *lassoc::Lecp_msgBody_get;
*swig_msgBody_set = *lassoc::Lecp_msgBody_set;
*swig_msgRelayState_get = *lassoc::Lecp_msgRelayState_get;
*swig_msgRelayState_set = *lassoc::Lecp_msgRelayState_set;
*swig_msgUrl_get = *lassoc::Lecp_msgUrl_get;
*swig_msgUrl_set = *lassoc::Lecp_msgUrl_set;
*swig_nameIdentifier_get = *lassoc::Lecp_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::Lecp_nameIdentifier_set;
*swig_remoteProviderId_get = *lassoc::Lecp_remoteProviderId_get;
*swig_remoteProviderId_set = *lassoc::Lecp_remoteProviderId_set;
*swig_request_get = *lassoc::Lecp_request_get;
*swig_request_set = *lassoc::Lecp_request_set;
*swig_response_get = *lassoc::Lecp_response_get;
*swig_response_set = *lassoc::Lecp_response_set;
*swig_server_get = *lassoc::Lecp_server_get;
*swig_server_set = *lassoc::Lecp_server_set;
*swig_session_get = *lassoc::Lecp_session_get;
*swig_session_set = *lassoc::Lecp_session_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Lecp(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Lecp($self);
        delete $OWNER{$self};
    }
}

*setIdentityFromDump = *lassoc::Lecp_setIdentityFromDump;
*setSessionFromDump = *lassoc::Lecp_setSessionFromDump;
*buildAssertion = *lassoc::Lecp_buildAssertion;
*setResourceId = *lassoc::Lecp_setResourceId;
*validateRequestMsg = *lassoc::Lecp_validateRequestMsg;
*buildAuthnRequestEnvelopeMsg = *lassoc::Lecp_buildAuthnRequestEnvelopeMsg;
*buildAuthnRequestMsg = *lassoc::Lecp_buildAuthnRequestMsg;
*buildAuthnResponseEnvelopeMsg = *lassoc::Lecp_buildAuthnResponseEnvelopeMsg;
*buildAuthnResponseMsg = *lassoc::Lecp_buildAuthnResponseMsg;
*initAuthnRequest = *lassoc::Lecp_initAuthnRequest;
*processAuthnRequestEnvelopeMsg = *lassoc::Lecp_processAuthnRequestEnvelopeMsg;
*processAuthnRequestMsg = *lassoc::Lecp_processAuthnRequestMsg;
*processAuthnResponseEnvelopeMsg = *lassoc::Lecp_processAuthnResponseEnvelopeMsg;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::NameIdentifierMapping ##############

package lasso::NameIdentifierMapping;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_targetNameIdentifier_get = *lassoc::NameIdentifierMapping_targetNameIdentifier_get;
*swig_targetNameIdentifier_set = *lassoc::NameIdentifierMapping_targetNameIdentifier_set;
*swig_artifact_get = *lassoc::NameIdentifierMapping_artifact_get;
*swig_artifact_set = *lassoc::NameIdentifierMapping_artifact_set;
*swig_artifactMessage_get = *lassoc::NameIdentifierMapping_artifactMessage_get;
*swig_artifactMessage_set = *lassoc::NameIdentifierMapping_artifactMessage_set;
*swig_identity_get = *lassoc::NameIdentifierMapping_identity_get;
*swig_identity_set = *lassoc::NameIdentifierMapping_identity_set;
*swig_isIdentityDirty_get = *lassoc::NameIdentifierMapping_isIdentityDirty_get;
*swig_isIdentityDirty_set = *lassoc::NameIdentifierMapping_isIdentityDirty_set;
*swig_isSessionDirty_get = *lassoc::NameIdentifierMapping_isSessionDirty_get;
*swig_isSessionDirty_set = *lassoc::NameIdentifierMapping_isSessionDirty_set;
*swig_msgBody_get = *lassoc::NameIdentifierMapping_msgBody_get;
*swig_msgBody_set = *lassoc::NameIdentifierMapping_msgBody_set;
*swig_msgUrl_get = *lassoc::NameIdentifierMapping_msgUrl_get;
*swig_msgUrl_set = *lassoc::NameIdentifierMapping_msgUrl_set;
*swig_nameIdentifier_get = *lassoc::NameIdentifierMapping_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::NameIdentifierMapping_nameIdentifier_set;
*swig_remoteProviderId_get = *lassoc::NameIdentifierMapping_remoteProviderId_get;
*swig_remoteProviderId_set = *lassoc::NameIdentifierMapping_remoteProviderId_set;
*swig_request_get = *lassoc::NameIdentifierMapping_request_get;
*swig_request_set = *lassoc::NameIdentifierMapping_request_set;
*swig_response_get = *lassoc::NameIdentifierMapping_response_get;
*swig_response_set = *lassoc::NameIdentifierMapping_response_set;
*swig_server_get = *lassoc::NameIdentifierMapping_server_get;
*swig_server_set = *lassoc::NameIdentifierMapping_server_set;
*swig_session_get = *lassoc::NameIdentifierMapping_session_get;
*swig_session_set = *lassoc::NameIdentifierMapping_session_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_NameIdentifierMapping(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_NameIdentifierMapping($self);
        delete $OWNER{$self};
    }
}

*setIdentityFromDump = *lassoc::NameIdentifierMapping_setIdentityFromDump;
*setSessionFromDump = *lassoc::NameIdentifierMapping_setSessionFromDump;
*buildRequestMsg = *lassoc::NameIdentifierMapping_buildRequestMsg;
*buildResponseMsg = *lassoc::NameIdentifierMapping_buildResponseMsg;
*initRequest = *lassoc::NameIdentifierMapping_initRequest;
*processRequestMsg = *lassoc::NameIdentifierMapping_processRequestMsg;
*processResponseMsg = *lassoc::NameIdentifierMapping_processResponseMsg;
*validateRequest = *lassoc::NameIdentifierMapping_validateRequest;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::NameRegistration ##############

package lasso::NameRegistration;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_artifact_get = *lassoc::NameRegistration_artifact_get;
*swig_artifact_set = *lassoc::NameRegistration_artifact_set;
*swig_artifactMessage_get = *lassoc::NameRegistration_artifactMessage_get;
*swig_artifactMessage_set = *lassoc::NameRegistration_artifactMessage_set;
*swig_identity_get = *lassoc::NameRegistration_identity_get;
*swig_identity_set = *lassoc::NameRegistration_identity_set;
*swig_isIdentityDirty_get = *lassoc::NameRegistration_isIdentityDirty_get;
*swig_isIdentityDirty_set = *lassoc::NameRegistration_isIdentityDirty_set;
*swig_isSessionDirty_get = *lassoc::NameRegistration_isSessionDirty_get;
*swig_isSessionDirty_set = *lassoc::NameRegistration_isSessionDirty_set;
*swig_msgBody_get = *lassoc::NameRegistration_msgBody_get;
*swig_msgBody_set = *lassoc::NameRegistration_msgBody_set;
*swig_msgRelayState_get = *lassoc::NameRegistration_msgRelayState_get;
*swig_msgRelayState_set = *lassoc::NameRegistration_msgRelayState_set;
*swig_msgUrl_get = *lassoc::NameRegistration_msgUrl_get;
*swig_msgUrl_set = *lassoc::NameRegistration_msgUrl_set;
*swig_nameIdentifier_get = *lassoc::NameRegistration_nameIdentifier_get;
*swig_nameIdentifier_set = *lassoc::NameRegistration_nameIdentifier_set;
*swig_remoteProviderId_get = *lassoc::NameRegistration_remoteProviderId_get;
*swig_remoteProviderId_set = *lassoc::NameRegistration_remoteProviderId_set;
*swig_request_get = *lassoc::NameRegistration_request_get;
*swig_request_set = *lassoc::NameRegistration_request_set;
*swig_response_get = *lassoc::NameRegistration_response_get;
*swig_response_set = *lassoc::NameRegistration_response_set;
*swig_server_get = *lassoc::NameRegistration_server_get;
*swig_server_set = *lassoc::NameRegistration_server_set;
*swig_session_get = *lassoc::NameRegistration_session_get;
*swig_session_set = *lassoc::NameRegistration_session_set;
*swig_oldNameIdentifier_get = *lassoc::NameRegistration_oldNameIdentifier_get;
*swig_oldNameIdentifier_set = *lassoc::NameRegistration_oldNameIdentifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_NameRegistration(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_NameRegistration($self);
        delete $OWNER{$self};
    }
}

*newFromDump = *lassoc::NameRegistration_newFromDump;
*setIdentityFromDump = *lassoc::NameRegistration_setIdentityFromDump;
*setSessionFromDump = *lassoc::NameRegistration_setSessionFromDump;
*buildRequestMsg = *lassoc::NameRegistration_buildRequestMsg;
*buildResponseMsg = *lassoc::NameRegistration_buildResponseMsg;
*dump = *lassoc::NameRegistration_dump;
*initRequest = *lassoc::NameRegistration_initRequest;
*processRequestMsg = *lassoc::NameRegistration_processRequestMsg;
*processResponseMsg = *lassoc::NameRegistration_processResponseMsg;
*validateRequest = *lassoc::NameRegistration_validateRequest;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2NameIDPolicy ##############

package lasso::Samlp2NameIDPolicy;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_format_get = *lassoc::Samlp2NameIDPolicy_format_get;
*swig_format_set = *lassoc::Samlp2NameIDPolicy_format_set;
*swig_SPNameQualifier_get = *lassoc::Samlp2NameIDPolicy_SPNameQualifier_get;
*swig_SPNameQualifier_set = *lassoc::Samlp2NameIDPolicy_SPNameQualifier_set;
*swig_allowCreate_get = *lassoc::Samlp2NameIDPolicy_allowCreate_get;
*swig_allowCreate_set = *lassoc::Samlp2NameIDPolicy_allowCreate_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2NameIDPolicy(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2NameIDPolicy($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2NameIDPolicy_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2RequestedAuthnContext ##############

package lasso::Samlp2RequestedAuthnContext;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_AuthnContextClassRef_get = *lassoc::Samlp2RequestedAuthnContext_AuthnContextClassRef_get;
*swig_AuthnContextClassRef_set = *lassoc::Samlp2RequestedAuthnContext_AuthnContextClassRef_set;
*swig_AuthnContextDeclRef_get = *lassoc::Samlp2RequestedAuthnContext_AuthnContextDeclRef_get;
*swig_AuthnContextDeclRef_set = *lassoc::Samlp2RequestedAuthnContext_AuthnContextDeclRef_set;
*swig_Comparison_get = *lassoc::Samlp2RequestedAuthnContext_Comparison_get;
*swig_Comparison_set = *lassoc::Samlp2RequestedAuthnContext_Comparison_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2RequestedAuthnContext(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2RequestedAuthnContext($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2RequestedAuthnContext_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2Assertion ##############

package lasso::Saml2Assertion;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Version_get = *lassoc::Saml2Assertion_Version_get;
*swig_Version_set = *lassoc::Saml2Assertion_Version_set;
*swig_ID_get = *lassoc::Saml2Assertion_ID_get;
*swig_ID_set = *lassoc::Saml2Assertion_ID_set;
*swig_issueInstant_get = *lassoc::Saml2Assertion_issueInstant_get;
*swig_issueInstant_set = *lassoc::Saml2Assertion_issueInstant_set;
*swig_issuer_get = *lassoc::Saml2Assertion_issuer_get;
*swig_issuer_set = *lassoc::Saml2Assertion_issuer_set;
*swig_subject_get = *lassoc::Saml2Assertion_subject_get;
*swig_subject_set = *lassoc::Saml2Assertion_subject_set;
*swig_conditions_get = *lassoc::Saml2Assertion_conditions_get;
*swig_conditions_set = *lassoc::Saml2Assertion_conditions_set;
*swig_advice_get = *lassoc::Saml2Assertion_advice_get;
*swig_advice_set = *lassoc::Saml2Assertion_advice_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2Assertion(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2Assertion($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2Assertion_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2IDPList ##############

package lasso::Samlp2IDPList;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_GetComplete_get = *lassoc::Samlp2IDPList_GetComplete_get;
*swig_GetComplete_set = *lassoc::Samlp2IDPList_GetComplete_set;
*swig_iDPEntry_get = *lassoc::Samlp2IDPList_iDPEntry_get;
*swig_iDPEntry_set = *lassoc::Samlp2IDPList_iDPEntry_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2IDPList(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2IDPList($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2IDPList_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2KeyInfoConfirmationData ##############

package lasso::Saml2KeyInfoConfirmationData;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2KeyInfoConfirmationData(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2KeyInfoConfirmationData($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2KeyInfoConfirmationData_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2Conditions ##############

package lasso::Saml2Conditions;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_notBefore_get = *lassoc::Saml2Conditions_notBefore_get;
*swig_notBefore_set = *lassoc::Saml2Conditions_notBefore_set;
*swig_notOnOrAfter_get = *lassoc::Saml2Conditions_notOnOrAfter_get;
*swig_notOnOrAfter_set = *lassoc::Saml2Conditions_notOnOrAfter_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2Conditions(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2Conditions($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2Conditions_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2Evidence ##############

package lasso::Saml2Evidence;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2Evidence(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2Evidence($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2Evidence_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2NameID ##############

package lasso::Saml2NameID;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_content_get = *lassoc::Saml2NameID_content_get;
*swig_content_set = *lassoc::Saml2NameID_content_set;
*swig_format_get = *lassoc::Saml2NameID_format_get;
*swig_format_set = *lassoc::Saml2NameID_format_set;
*swig_SPProvidedID_get = *lassoc::Saml2NameID_SPProvidedID_get;
*swig_SPProvidedID_set = *lassoc::Saml2NameID_SPProvidedID_set;
*swig_nameQualifier_get = *lassoc::Saml2NameID_nameQualifier_get;
*swig_nameQualifier_set = *lassoc::Saml2NameID_nameQualifier_set;
*swig_SPNameQualifier_get = *lassoc::Saml2NameID_SPNameQualifier_get;
*swig_SPNameQualifier_set = *lassoc::Saml2NameID_SPNameQualifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2NameID(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2NameID($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2NameID_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2StatusCode ##############

package lasso::Samlp2StatusCode;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_value_get = *lassoc::Samlp2StatusCode_value_get;
*swig_value_set = *lassoc::Samlp2StatusCode_value_set;
*swig_statusCode_get = *lassoc::Samlp2StatusCode_statusCode_get;
*swig_statusCode_set = *lassoc::Samlp2StatusCode_statusCode_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2StatusCode(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2StatusCode($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2StatusCode_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2Status ##############

package lasso::Samlp2Status;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_statusMessage_get = *lassoc::Samlp2Status_statusMessage_get;
*swig_statusMessage_set = *lassoc::Samlp2Status_statusMessage_set;
*swig_statusCode_get = *lassoc::Samlp2Status_statusCode_get;
*swig_statusCode_set = *lassoc::Samlp2Status_statusCode_set;
*swig_statusDetail_get = *lassoc::Samlp2Status_statusDetail_get;
*swig_statusDetail_set = *lassoc::Samlp2Status_statusDetail_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2Status(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2Status($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2Status_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2ConditionAbstract ##############

package lasso::Saml2ConditionAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2ConditionAbstract(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2ConditionAbstract($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2ConditionAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2OneTimeUse ##############

package lasso::Saml2OneTimeUse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2OneTimeUse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2OneTimeUse($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2OneTimeUse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2Advice ##############

package lasso::Saml2Advice;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2Advice(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2Advice($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2Advice_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2BaseIDAbstract ##############

package lasso::Saml2BaseIDAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_nameQualifier_get = *lassoc::Saml2BaseIDAbstract_nameQualifier_get;
*swig_nameQualifier_set = *lassoc::Saml2BaseIDAbstract_nameQualifier_set;
*swig_SPNameQualifier_get = *lassoc::Saml2BaseIDAbstract_SPNameQualifier_get;
*swig_SPNameQualifier_set = *lassoc::Saml2BaseIDAbstract_SPNameQualifier_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2BaseIDAbstract(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2BaseIDAbstract($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2BaseIDAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2AuthnContext ##############

package lasso::Saml2AuthnContext;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_AuthnContextClassRef_get = *lassoc::Saml2AuthnContext_AuthnContextClassRef_get;
*swig_AuthnContextClassRef_set = *lassoc::Saml2AuthnContext_AuthnContextClassRef_set;
*swig_AuthnContextDeclRef_get = *lassoc::Saml2AuthnContext_AuthnContextDeclRef_get;
*swig_AuthnContextDeclRef_set = *lassoc::Saml2AuthnContext_AuthnContextDeclRef_set;
*swig_AuthenticatingAuthority_get = *lassoc::Saml2AuthnContext_AuthenticatingAuthority_get;
*swig_AuthenticatingAuthority_set = *lassoc::Saml2AuthnContext_AuthenticatingAuthority_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2AuthnContext(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2AuthnContext($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2AuthnContext_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2SubjectLocality ##############

package lasso::Saml2SubjectLocality;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Address_get = *lassoc::Saml2SubjectLocality_Address_get;
*swig_Address_set = *lassoc::Saml2SubjectLocality_Address_set;
*swig_DNSName_get = *lassoc::Saml2SubjectLocality_DNSName_get;
*swig_DNSName_set = *lassoc::Saml2SubjectLocality_DNSName_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2SubjectLocality(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2SubjectLocality($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2SubjectLocality_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2SubjectConfirmationData ##############

package lasso::Saml2SubjectConfirmationData;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_notBefore_get = *lassoc::Saml2SubjectConfirmationData_notBefore_get;
*swig_notBefore_set = *lassoc::Saml2SubjectConfirmationData_notBefore_set;
*swig_notOnOrAfter_get = *lassoc::Saml2SubjectConfirmationData_notOnOrAfter_get;
*swig_notOnOrAfter_set = *lassoc::Saml2SubjectConfirmationData_notOnOrAfter_set;
*swig_recipient_get = *lassoc::Saml2SubjectConfirmationData_recipient_get;
*swig_recipient_set = *lassoc::Saml2SubjectConfirmationData_recipient_set;
*swig_inResponseTo_get = *lassoc::Saml2SubjectConfirmationData_inResponseTo_get;
*swig_inResponseTo_set = *lassoc::Saml2SubjectConfirmationData_inResponseTo_set;
*swig_Address_get = *lassoc::Saml2SubjectConfirmationData_Address_get;
*swig_Address_set = *lassoc::Saml2SubjectConfirmationData_Address_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2SubjectConfirmationData(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2SubjectConfirmationData($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2SubjectConfirmationData_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2SubjectConfirmation ##############

package lasso::Saml2SubjectConfirmation;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Method_get = *lassoc::Saml2SubjectConfirmation_Method_get;
*swig_Method_set = *lassoc::Saml2SubjectConfirmation_Method_set;
*swig_baseID_get = *lassoc::Saml2SubjectConfirmation_baseID_get;
*swig_baseID_set = *lassoc::Saml2SubjectConfirmation_baseID_set;
*swig_nameID_get = *lassoc::Saml2SubjectConfirmation_nameID_get;
*swig_nameID_set = *lassoc::Saml2SubjectConfirmation_nameID_set;
*swig_encryptedID_get = *lassoc::Saml2SubjectConfirmation_encryptedID_get;
*swig_encryptedID_set = *lassoc::Saml2SubjectConfirmation_encryptedID_set;
*swig_subjectConfirmationData_get = *lassoc::Saml2SubjectConfirmation_subjectConfirmationData_get;
*swig_subjectConfirmationData_set = *lassoc::Saml2SubjectConfirmation_subjectConfirmationData_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2SubjectConfirmation(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2SubjectConfirmation($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2SubjectConfirmation_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2ProxyRestriction ##############

package lasso::Saml2ProxyRestriction;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Audience_get = *lassoc::Saml2ProxyRestriction_Audience_get;
*swig_Audience_set = *lassoc::Saml2ProxyRestriction_Audience_set;
*swig_Count_get = *lassoc::Saml2ProxyRestriction_Count_get;
*swig_Count_set = *lassoc::Saml2ProxyRestriction_Count_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2ProxyRestriction(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2ProxyRestriction($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2ProxyRestriction_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2StatementAbstract ##############

package lasso::Saml2StatementAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2StatementAbstract(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2StatementAbstract($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2StatementAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2AuthnStatement ##############

package lasso::Saml2AuthnStatement;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_AuthnInstant_get = *lassoc::Saml2AuthnStatement_AuthnInstant_get;
*swig_AuthnInstant_set = *lassoc::Saml2AuthnStatement_AuthnInstant_set;
*swig_sessionIndex_get = *lassoc::Saml2AuthnStatement_sessionIndex_get;
*swig_sessionIndex_set = *lassoc::Saml2AuthnStatement_sessionIndex_set;
*swig_SessionNotOnOrAfter_get = *lassoc::Saml2AuthnStatement_SessionNotOnOrAfter_get;
*swig_SessionNotOnOrAfter_set = *lassoc::Saml2AuthnStatement_SessionNotOnOrAfter_set;
*swig_subjectLocality_get = *lassoc::Saml2AuthnStatement_subjectLocality_get;
*swig_subjectLocality_set = *lassoc::Saml2AuthnStatement_subjectLocality_set;
*swig_authnContext_get = *lassoc::Saml2AuthnStatement_authnContext_get;
*swig_authnContext_set = *lassoc::Saml2AuthnStatement_authnContext_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2AuthnStatement(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2AuthnStatement($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2AuthnStatement_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2AttributeStatement ##############

package lasso::Saml2AttributeStatement;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2AttributeStatement(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2AttributeStatement($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2AttributeStatement_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2IDPEntry ##############

package lasso::Samlp2IDPEntry;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_providerId_get = *lassoc::Samlp2IDPEntry_providerId_get;
*swig_providerId_set = *lassoc::Samlp2IDPEntry_providerId_set;
*swig_Name_get = *lassoc::Samlp2IDPEntry_Name_get;
*swig_Name_set = *lassoc::Samlp2IDPEntry_Name_set;
*swig_Loc_get = *lassoc::Samlp2IDPEntry_Loc_get;
*swig_Loc_set = *lassoc::Samlp2IDPEntry_Loc_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2IDPEntry(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2IDPEntry($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2IDPEntry_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2Extensions ##############

package lasso::Samlp2Extensions;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2Extensions(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2Extensions($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2Extensions_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2Action ##############

package lasso::Saml2Action;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_content_get = *lassoc::Saml2Action_content_get;
*swig_content_set = *lassoc::Saml2Action_content_set;
*swig_Namespace_get = *lassoc::Saml2Action_Namespace_get;
*swig_Namespace_set = *lassoc::Saml2Action_Namespace_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2Action(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2Action($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2Action_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2StatusResponse ##############

package lasso::Samlp2StatusResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_ID_get = *lassoc::Samlp2StatusResponse_ID_get;
*swig_ID_set = *lassoc::Samlp2StatusResponse_ID_set;
*swig_inResponseTo_get = *lassoc::Samlp2StatusResponse_inResponseTo_get;
*swig_inResponseTo_set = *lassoc::Samlp2StatusResponse_inResponseTo_set;
*swig_Version_get = *lassoc::Samlp2StatusResponse_Version_get;
*swig_Version_set = *lassoc::Samlp2StatusResponse_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2StatusResponse_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2StatusResponse_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2StatusResponse_Destination_get;
*swig_Destination_set = *lassoc::Samlp2StatusResponse_Destination_set;
*swig_Consent_get = *lassoc::Samlp2StatusResponse_Consent_get;
*swig_Consent_set = *lassoc::Samlp2StatusResponse_Consent_set;
*swig_issuer_get = *lassoc::Samlp2StatusResponse_issuer_get;
*swig_issuer_set = *lassoc::Samlp2StatusResponse_issuer_set;
*swig_extensions_get = *lassoc::Samlp2StatusResponse_extensions_get;
*swig_extensions_set = *lassoc::Samlp2StatusResponse_extensions_set;
*swig_status_get = *lassoc::Samlp2StatusResponse_status_get;
*swig_status_set = *lassoc::Samlp2StatusResponse_status_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2StatusResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2StatusResponse($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2StatusResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2Response ##############

package lasso::Samlp2Response;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_issuer_get = *lassoc::Samlp2Response_issuer_get;
*swig_issuer_set = *lassoc::Samlp2Response_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2Response_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2Response_Extensions_set;
*swig_Status_get = *lassoc::Samlp2Response_Status_get;
*swig_Status_set = *lassoc::Samlp2Response_Status_set;
*swig_ID_get = *lassoc::Samlp2Response_ID_get;
*swig_ID_set = *lassoc::Samlp2Response_ID_set;
*swig_inResponseTo_get = *lassoc::Samlp2Response_inResponseTo_get;
*swig_inResponseTo_set = *lassoc::Samlp2Response_inResponseTo_set;
*swig_Version_get = *lassoc::Samlp2Response_Version_get;
*swig_Version_set = *lassoc::Samlp2Response_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2Response_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2Response_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2Response_Destination_get;
*swig_Destination_set = *lassoc::Samlp2Response_Destination_set;
*swig_Consent_get = *lassoc::Samlp2Response_Consent_get;
*swig_Consent_set = *lassoc::Samlp2Response_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2Response(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2Response($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2Response_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2ArtifactResponse ##############

package lasso::Samlp2ArtifactResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_any_get = *lassoc::Samlp2ArtifactResponse_any_get;
*swig_any_set = *lassoc::Samlp2ArtifactResponse_any_set;
*swig_issuer_get = *lassoc::Samlp2ArtifactResponse_issuer_get;
*swig_issuer_set = *lassoc::Samlp2ArtifactResponse_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2ArtifactResponse_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2ArtifactResponse_Extensions_set;
*swig_Status_get = *lassoc::Samlp2ArtifactResponse_Status_get;
*swig_Status_set = *lassoc::Samlp2ArtifactResponse_Status_set;
*swig_ID_get = *lassoc::Samlp2ArtifactResponse_ID_get;
*swig_ID_set = *lassoc::Samlp2ArtifactResponse_ID_set;
*swig_inResponseTo_get = *lassoc::Samlp2ArtifactResponse_inResponseTo_get;
*swig_inResponseTo_set = *lassoc::Samlp2ArtifactResponse_inResponseTo_set;
*swig_Version_get = *lassoc::Samlp2ArtifactResponse_Version_get;
*swig_Version_set = *lassoc::Samlp2ArtifactResponse_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2ArtifactResponse_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2ArtifactResponse_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2ArtifactResponse_Destination_get;
*swig_Destination_set = *lassoc::Samlp2ArtifactResponse_Destination_set;
*swig_Consent_get = *lassoc::Samlp2ArtifactResponse_Consent_get;
*swig_Consent_set = *lassoc::Samlp2ArtifactResponse_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2ArtifactResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2ArtifactResponse($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2ArtifactResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2RequestAbstract ##############

package lasso::Samlp2RequestAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_ID_get = *lassoc::Samlp2RequestAbstract_ID_get;
*swig_ID_set = *lassoc::Samlp2RequestAbstract_ID_set;
*swig_Version_get = *lassoc::Samlp2RequestAbstract_Version_get;
*swig_Version_set = *lassoc::Samlp2RequestAbstract_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2RequestAbstract_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2RequestAbstract_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2RequestAbstract_Destination_get;
*swig_Destination_set = *lassoc::Samlp2RequestAbstract_Destination_set;
*swig_Consent_get = *lassoc::Samlp2RequestAbstract_Consent_get;
*swig_Consent_set = *lassoc::Samlp2RequestAbstract_Consent_set;
*swig_issuer_get = *lassoc::Samlp2RequestAbstract_issuer_get;
*swig_issuer_set = *lassoc::Samlp2RequestAbstract_issuer_set;
*swig_extensions_get = *lassoc::Samlp2RequestAbstract_extensions_get;
*swig_extensions_set = *lassoc::Samlp2RequestAbstract_extensions_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2RequestAbstract(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2RequestAbstract($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2RequestAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2AssertionIDRequest ##############

package lasso::Samlp2AssertionIDRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_AssertionIDRef_get = *lassoc::Samlp2AssertionIDRequest_AssertionIDRef_get;
*swig_AssertionIDRef_set = *lassoc::Samlp2AssertionIDRequest_AssertionIDRef_set;
*swig_issuer_get = *lassoc::Samlp2AssertionIDRequest_issuer_get;
*swig_issuer_set = *lassoc::Samlp2AssertionIDRequest_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2AssertionIDRequest_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2AssertionIDRequest_Extensions_set;
*swig_ID_get = *lassoc::Samlp2AssertionIDRequest_ID_get;
*swig_ID_set = *lassoc::Samlp2AssertionIDRequest_ID_set;
*swig_Version_get = *lassoc::Samlp2AssertionIDRequest_Version_get;
*swig_Version_set = *lassoc::Samlp2AssertionIDRequest_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2AssertionIDRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2AssertionIDRequest_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2AssertionIDRequest_Destination_get;
*swig_Destination_set = *lassoc::Samlp2AssertionIDRequest_Destination_set;
*swig_Consent_get = *lassoc::Samlp2AssertionIDRequest_Consent_get;
*swig_Consent_set = *lassoc::Samlp2AssertionIDRequest_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2AssertionIDRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2AssertionIDRequest($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2AssertionIDRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2ArtifactResolve ##############

package lasso::Samlp2ArtifactResolve;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Artifact_get = *lassoc::Samlp2ArtifactResolve_Artifact_get;
*swig_Artifact_set = *lassoc::Samlp2ArtifactResolve_Artifact_set;
*swig_issuer_get = *lassoc::Samlp2ArtifactResolve_issuer_get;
*swig_issuer_set = *lassoc::Samlp2ArtifactResolve_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2ArtifactResolve_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2ArtifactResolve_Extensions_set;
*swig_ID_get = *lassoc::Samlp2ArtifactResolve_ID_get;
*swig_ID_set = *lassoc::Samlp2ArtifactResolve_ID_set;
*swig_Version_get = *lassoc::Samlp2ArtifactResolve_Version_get;
*swig_Version_set = *lassoc::Samlp2ArtifactResolve_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2ArtifactResolve_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2ArtifactResolve_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2ArtifactResolve_Destination_get;
*swig_Destination_set = *lassoc::Samlp2ArtifactResolve_Destination_set;
*swig_Consent_get = *lassoc::Samlp2ArtifactResolve_Consent_get;
*swig_Consent_set = *lassoc::Samlp2ArtifactResolve_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2ArtifactResolve(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2ArtifactResolve($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2ArtifactResolve_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2NameIDMappingRequest ##############

package lasso::Samlp2NameIDMappingRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_baseID_get = *lassoc::Samlp2NameIDMappingRequest_baseID_get;
*swig_baseID_set = *lassoc::Samlp2NameIDMappingRequest_baseID_set;
*swig_nameID_get = *lassoc::Samlp2NameIDMappingRequest_nameID_get;
*swig_nameID_set = *lassoc::Samlp2NameIDMappingRequest_nameID_set;
*swig_encryptedID_get = *lassoc::Samlp2NameIDMappingRequest_encryptedID_get;
*swig_encryptedID_set = *lassoc::Samlp2NameIDMappingRequest_encryptedID_set;
*swig_nameIDPolicy_get = *lassoc::Samlp2NameIDMappingRequest_nameIDPolicy_get;
*swig_nameIDPolicy_set = *lassoc::Samlp2NameIDMappingRequest_nameIDPolicy_set;
*swig_issuer_get = *lassoc::Samlp2NameIDMappingRequest_issuer_get;
*swig_issuer_set = *lassoc::Samlp2NameIDMappingRequest_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2NameIDMappingRequest_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2NameIDMappingRequest_Extensions_set;
*swig_ID_get = *lassoc::Samlp2NameIDMappingRequest_ID_get;
*swig_ID_set = *lassoc::Samlp2NameIDMappingRequest_ID_set;
*swig_Version_get = *lassoc::Samlp2NameIDMappingRequest_Version_get;
*swig_Version_set = *lassoc::Samlp2NameIDMappingRequest_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2NameIDMappingRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2NameIDMappingRequest_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2NameIDMappingRequest_Destination_get;
*swig_Destination_set = *lassoc::Samlp2NameIDMappingRequest_Destination_set;
*swig_Consent_get = *lassoc::Samlp2NameIDMappingRequest_Consent_get;
*swig_Consent_set = *lassoc::Samlp2NameIDMappingRequest_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2NameIDMappingRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2NameIDMappingRequest($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2NameIDMappingRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2AuthnRequest ##############

package lasso::Samlp2AuthnRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_forceAuthn_get = *lassoc::Samlp2AuthnRequest_forceAuthn_get;
*swig_forceAuthn_set = *lassoc::Samlp2AuthnRequest_forceAuthn_set;
*swig_isPassive_get = *lassoc::Samlp2AuthnRequest_isPassive_get;
*swig_isPassive_set = *lassoc::Samlp2AuthnRequest_isPassive_set;
*swig_ProtocolBinding_get = *lassoc::Samlp2AuthnRequest_ProtocolBinding_get;
*swig_ProtocolBinding_set = *lassoc::Samlp2AuthnRequest_ProtocolBinding_set;
*swig_assertionConsumerServiceIndex_get = *lassoc::Samlp2AuthnRequest_assertionConsumerServiceIndex_get;
*swig_assertionConsumerServiceIndex_set = *lassoc::Samlp2AuthnRequest_assertionConsumerServiceIndex_set;
*swig_AssertionConsumerServiceURL_get = *lassoc::Samlp2AuthnRequest_AssertionConsumerServiceURL_get;
*swig_AssertionConsumerServiceURL_set = *lassoc::Samlp2AuthnRequest_AssertionConsumerServiceURL_set;
*swig_attributeConsumingServiceIndex_get = *lassoc::Samlp2AuthnRequest_attributeConsumingServiceIndex_get;
*swig_attributeConsumingServiceIndex_set = *lassoc::Samlp2AuthnRequest_attributeConsumingServiceIndex_set;
*swig_ProviderName_get = *lassoc::Samlp2AuthnRequest_ProviderName_get;
*swig_ProviderName_set = *lassoc::Samlp2AuthnRequest_ProviderName_set;
*swig_subject_get = *lassoc::Samlp2AuthnRequest_subject_get;
*swig_subject_set = *lassoc::Samlp2AuthnRequest_subject_set;
*swig_nameIDPolicy_get = *lassoc::Samlp2AuthnRequest_nameIDPolicy_get;
*swig_nameIDPolicy_set = *lassoc::Samlp2AuthnRequest_nameIDPolicy_set;
*swig_conditions_get = *lassoc::Samlp2AuthnRequest_conditions_get;
*swig_conditions_set = *lassoc::Samlp2AuthnRequest_conditions_set;
*swig_requestedAuthnContext_get = *lassoc::Samlp2AuthnRequest_requestedAuthnContext_get;
*swig_requestedAuthnContext_set = *lassoc::Samlp2AuthnRequest_requestedAuthnContext_set;
*swig_scoping_get = *lassoc::Samlp2AuthnRequest_scoping_get;
*swig_scoping_set = *lassoc::Samlp2AuthnRequest_scoping_set;
*swig_issuer_get = *lassoc::Samlp2AuthnRequest_issuer_get;
*swig_issuer_set = *lassoc::Samlp2AuthnRequest_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2AuthnRequest_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2AuthnRequest_Extensions_set;
*swig_ID_get = *lassoc::Samlp2AuthnRequest_ID_get;
*swig_ID_set = *lassoc::Samlp2AuthnRequest_ID_set;
*swig_Version_get = *lassoc::Samlp2AuthnRequest_Version_get;
*swig_Version_set = *lassoc::Samlp2AuthnRequest_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2AuthnRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2AuthnRequest_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2AuthnRequest_Destination_get;
*swig_Destination_set = *lassoc::Samlp2AuthnRequest_Destination_set;
*swig_Consent_get = *lassoc::Samlp2AuthnRequest_Consent_get;
*swig_Consent_set = *lassoc::Samlp2AuthnRequest_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2AuthnRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2AuthnRequest($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2AuthnRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2SubjectQueryAbstract ##############

package lasso::Samlp2SubjectQueryAbstract;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_subject_get = *lassoc::Samlp2SubjectQueryAbstract_subject_get;
*swig_subject_set = *lassoc::Samlp2SubjectQueryAbstract_subject_set;
*swig_issuer_get = *lassoc::Samlp2SubjectQueryAbstract_issuer_get;
*swig_issuer_set = *lassoc::Samlp2SubjectQueryAbstract_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2SubjectQueryAbstract_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2SubjectQueryAbstract_Extensions_set;
*swig_ID_get = *lassoc::Samlp2SubjectQueryAbstract_ID_get;
*swig_ID_set = *lassoc::Samlp2SubjectQueryAbstract_ID_set;
*swig_Version_get = *lassoc::Samlp2SubjectQueryAbstract_Version_get;
*swig_Version_set = *lassoc::Samlp2SubjectQueryAbstract_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2SubjectQueryAbstract_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2SubjectQueryAbstract_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2SubjectQueryAbstract_Destination_get;
*swig_Destination_set = *lassoc::Samlp2SubjectQueryAbstract_Destination_set;
*swig_Consent_get = *lassoc::Samlp2SubjectQueryAbstract_Consent_get;
*swig_Consent_set = *lassoc::Samlp2SubjectQueryAbstract_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2SubjectQueryAbstract(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2SubjectQueryAbstract($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2SubjectQueryAbstract_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2AuthzDecisionQuery ##############

package lasso::Samlp2AuthzDecisionQuery;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Resource_get = *lassoc::Samlp2AuthzDecisionQuery_Resource_get;
*swig_Resource_set = *lassoc::Samlp2AuthzDecisionQuery_Resource_set;
*swig_action_get = *lassoc::Samlp2AuthzDecisionQuery_action_get;
*swig_action_set = *lassoc::Samlp2AuthzDecisionQuery_action_set;
*swig_evidence_get = *lassoc::Samlp2AuthzDecisionQuery_evidence_get;
*swig_evidence_set = *lassoc::Samlp2AuthzDecisionQuery_evidence_set;
*swig_Subject_get = *lassoc::Samlp2AuthzDecisionQuery_Subject_get;
*swig_Subject_set = *lassoc::Samlp2AuthzDecisionQuery_Subject_set;
*swig_issuer_get = *lassoc::Samlp2AuthzDecisionQuery_issuer_get;
*swig_issuer_set = *lassoc::Samlp2AuthzDecisionQuery_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2AuthzDecisionQuery_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2AuthzDecisionQuery_Extensions_set;
*swig_ID_get = *lassoc::Samlp2AuthzDecisionQuery_ID_get;
*swig_ID_set = *lassoc::Samlp2AuthzDecisionQuery_ID_set;
*swig_Version_get = *lassoc::Samlp2AuthzDecisionQuery_Version_get;
*swig_Version_set = *lassoc::Samlp2AuthzDecisionQuery_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2AuthzDecisionQuery_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2AuthzDecisionQuery_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2AuthzDecisionQuery_Destination_get;
*swig_Destination_set = *lassoc::Samlp2AuthzDecisionQuery_Destination_set;
*swig_Consent_get = *lassoc::Samlp2AuthzDecisionQuery_Consent_get;
*swig_Consent_set = *lassoc::Samlp2AuthzDecisionQuery_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2AuthzDecisionQuery(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2AuthzDecisionQuery($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2AuthzDecisionQuery_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2AttributeQuery ##############

package lasso::Samlp2AttributeQuery;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_attribute_get = *lassoc::Samlp2AttributeQuery_attribute_get;
*swig_attribute_set = *lassoc::Samlp2AttributeQuery_attribute_set;
*swig_Subject_get = *lassoc::Samlp2AttributeQuery_Subject_get;
*swig_Subject_set = *lassoc::Samlp2AttributeQuery_Subject_set;
*swig_issuer_get = *lassoc::Samlp2AttributeQuery_issuer_get;
*swig_issuer_set = *lassoc::Samlp2AttributeQuery_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2AttributeQuery_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2AttributeQuery_Extensions_set;
*swig_ID_get = *lassoc::Samlp2AttributeQuery_ID_get;
*swig_ID_set = *lassoc::Samlp2AttributeQuery_ID_set;
*swig_Version_get = *lassoc::Samlp2AttributeQuery_Version_get;
*swig_Version_set = *lassoc::Samlp2AttributeQuery_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2AttributeQuery_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2AttributeQuery_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2AttributeQuery_Destination_get;
*swig_Destination_set = *lassoc::Samlp2AttributeQuery_Destination_set;
*swig_Consent_get = *lassoc::Samlp2AttributeQuery_Consent_get;
*swig_Consent_set = *lassoc::Samlp2AttributeQuery_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2AttributeQuery(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2AttributeQuery($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2AttributeQuery_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2AudienceRestriction ##############

package lasso::Saml2AudienceRestriction;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Audience_get = *lassoc::Saml2AudienceRestriction_Audience_get;
*swig_Audience_set = *lassoc::Saml2AudienceRestriction_Audience_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2AudienceRestriction(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2AudienceRestriction($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2AudienceRestriction_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2LogoutRequest ##############

package lasso::Samlp2LogoutRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_sessionIndex_get = *lassoc::Samlp2LogoutRequest_sessionIndex_get;
*swig_sessionIndex_set = *lassoc::Samlp2LogoutRequest_sessionIndex_set;
*swig_Reason_get = *lassoc::Samlp2LogoutRequest_Reason_get;
*swig_Reason_set = *lassoc::Samlp2LogoutRequest_Reason_set;
*swig_notOnOrAfter_get = *lassoc::Samlp2LogoutRequest_notOnOrAfter_get;
*swig_notOnOrAfter_set = *lassoc::Samlp2LogoutRequest_notOnOrAfter_set;
*swig_baseID_get = *lassoc::Samlp2LogoutRequest_baseID_get;
*swig_baseID_set = *lassoc::Samlp2LogoutRequest_baseID_set;
*swig_nameID_get = *lassoc::Samlp2LogoutRequest_nameID_get;
*swig_nameID_set = *lassoc::Samlp2LogoutRequest_nameID_set;
*swig_encryptedID_get = *lassoc::Samlp2LogoutRequest_encryptedID_get;
*swig_encryptedID_set = *lassoc::Samlp2LogoutRequest_encryptedID_set;
*swig_issuer_get = *lassoc::Samlp2LogoutRequest_issuer_get;
*swig_issuer_set = *lassoc::Samlp2LogoutRequest_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2LogoutRequest_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2LogoutRequest_Extensions_set;
*swig_ID_get = *lassoc::Samlp2LogoutRequest_ID_get;
*swig_ID_set = *lassoc::Samlp2LogoutRequest_ID_set;
*swig_Version_get = *lassoc::Samlp2LogoutRequest_Version_get;
*swig_Version_set = *lassoc::Samlp2LogoutRequest_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2LogoutRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2LogoutRequest_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2LogoutRequest_Destination_get;
*swig_Destination_set = *lassoc::Samlp2LogoutRequest_Destination_set;
*swig_Consent_get = *lassoc::Samlp2LogoutRequest_Consent_get;
*swig_Consent_set = *lassoc::Samlp2LogoutRequest_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2LogoutRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2LogoutRequest($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2LogoutRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2AuthnQuery ##############

package lasso::Samlp2AuthnQuery;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_sessionIndex_get = *lassoc::Samlp2AuthnQuery_sessionIndex_get;
*swig_sessionIndex_set = *lassoc::Samlp2AuthnQuery_sessionIndex_set;
*swig_requestedAuthnContext_get = *lassoc::Samlp2AuthnQuery_requestedAuthnContext_get;
*swig_requestedAuthnContext_set = *lassoc::Samlp2AuthnQuery_requestedAuthnContext_set;
*swig_Subject_get = *lassoc::Samlp2AuthnQuery_Subject_get;
*swig_Subject_set = *lassoc::Samlp2AuthnQuery_Subject_set;
*swig_issuer_get = *lassoc::Samlp2AuthnQuery_issuer_get;
*swig_issuer_set = *lassoc::Samlp2AuthnQuery_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2AuthnQuery_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2AuthnQuery_Extensions_set;
*swig_ID_get = *lassoc::Samlp2AuthnQuery_ID_get;
*swig_ID_set = *lassoc::Samlp2AuthnQuery_ID_set;
*swig_Version_get = *lassoc::Samlp2AuthnQuery_Version_get;
*swig_Version_set = *lassoc::Samlp2AuthnQuery_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2AuthnQuery_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2AuthnQuery_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2AuthnQuery_Destination_get;
*swig_Destination_set = *lassoc::Samlp2AuthnQuery_Destination_set;
*swig_Consent_get = *lassoc::Samlp2AuthnQuery_Consent_get;
*swig_Consent_set = *lassoc::Samlp2AuthnQuery_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2AuthnQuery(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2AuthnQuery($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2AuthnQuery_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2Attribute ##############

package lasso::Saml2Attribute;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Name_get = *lassoc::Saml2Attribute_Name_get;
*swig_Name_set = *lassoc::Saml2Attribute_Name_set;
*swig_NameFormat_get = *lassoc::Saml2Attribute_NameFormat_get;
*swig_NameFormat_set = *lassoc::Saml2Attribute_NameFormat_set;
*swig_FriendlyName_get = *lassoc::Saml2Attribute_FriendlyName_get;
*swig_FriendlyName_set = *lassoc::Saml2Attribute_FriendlyName_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2Attribute(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2Attribute($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2Attribute_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2Terminate ##############

package lasso::Samlp2Terminate;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2Terminate(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2Terminate($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2Terminate_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2StatusDetail ##############

package lasso::Samlp2StatusDetail;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2StatusDetail(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2StatusDetail($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2StatusDetail_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2AuthzDecisionStatement ##############

package lasso::Saml2AuthzDecisionStatement;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_Resource_get = *lassoc::Saml2AuthzDecisionStatement_Resource_get;
*swig_Resource_set = *lassoc::Saml2AuthzDecisionStatement_Resource_set;
*swig_Decision_get = *lassoc::Saml2AuthzDecisionStatement_Decision_get;
*swig_Decision_set = *lassoc::Saml2AuthzDecisionStatement_Decision_set;
*swig_action_get = *lassoc::Saml2AuthzDecisionStatement_action_get;
*swig_action_set = *lassoc::Saml2AuthzDecisionStatement_action_set;
*swig_evidence_get = *lassoc::Saml2AuthzDecisionStatement_evidence_get;
*swig_evidence_set = *lassoc::Saml2AuthzDecisionStatement_evidence_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2AuthzDecisionStatement(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2AuthzDecisionStatement($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2AuthzDecisionStatement_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2NameIDMappingResponse ##############

package lasso::Samlp2NameIDMappingResponse;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_nameID_get = *lassoc::Samlp2NameIDMappingResponse_nameID_get;
*swig_nameID_set = *lassoc::Samlp2NameIDMappingResponse_nameID_set;
*swig_encryptedID_get = *lassoc::Samlp2NameIDMappingResponse_encryptedID_get;
*swig_encryptedID_set = *lassoc::Samlp2NameIDMappingResponse_encryptedID_set;
*swig_issuer_get = *lassoc::Samlp2NameIDMappingResponse_issuer_get;
*swig_issuer_set = *lassoc::Samlp2NameIDMappingResponse_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2NameIDMappingResponse_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2NameIDMappingResponse_Extensions_set;
*swig_Status_get = *lassoc::Samlp2NameIDMappingResponse_Status_get;
*swig_Status_set = *lassoc::Samlp2NameIDMappingResponse_Status_set;
*swig_ID_get = *lassoc::Samlp2NameIDMappingResponse_ID_get;
*swig_ID_set = *lassoc::Samlp2NameIDMappingResponse_ID_set;
*swig_inResponseTo_get = *lassoc::Samlp2NameIDMappingResponse_inResponseTo_get;
*swig_inResponseTo_set = *lassoc::Samlp2NameIDMappingResponse_inResponseTo_set;
*swig_Version_get = *lassoc::Samlp2NameIDMappingResponse_Version_get;
*swig_Version_set = *lassoc::Samlp2NameIDMappingResponse_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2NameIDMappingResponse_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2NameIDMappingResponse_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2NameIDMappingResponse_Destination_get;
*swig_Destination_set = *lassoc::Samlp2NameIDMappingResponse_Destination_set;
*swig_Consent_get = *lassoc::Samlp2NameIDMappingResponse_Consent_get;
*swig_Consent_set = *lassoc::Samlp2NameIDMappingResponse_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2NameIDMappingResponse(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2NameIDMappingResponse($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2NameIDMappingResponse_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2EncryptedElement ##############

package lasso::Saml2EncryptedElement;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2EncryptedElement(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2EncryptedElement($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2EncryptedElement_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2ManageNameIDRequest ##############

package lasso::Samlp2ManageNameIDRequest;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_NewID_get = *lassoc::Samlp2ManageNameIDRequest_NewID_get;
*swig_NewID_set = *lassoc::Samlp2ManageNameIDRequest_NewID_set;
*swig_nameID_get = *lassoc::Samlp2ManageNameIDRequest_nameID_get;
*swig_nameID_set = *lassoc::Samlp2ManageNameIDRequest_nameID_set;
*swig_encryptedID_get = *lassoc::Samlp2ManageNameIDRequest_encryptedID_get;
*swig_encryptedID_set = *lassoc::Samlp2ManageNameIDRequest_encryptedID_set;
*swig_newEncryptedID_get = *lassoc::Samlp2ManageNameIDRequest_newEncryptedID_get;
*swig_newEncryptedID_set = *lassoc::Samlp2ManageNameIDRequest_newEncryptedID_set;
*swig_terminate_get = *lassoc::Samlp2ManageNameIDRequest_terminate_get;
*swig_terminate_set = *lassoc::Samlp2ManageNameIDRequest_terminate_set;
*swig_issuer_get = *lassoc::Samlp2ManageNameIDRequest_issuer_get;
*swig_issuer_set = *lassoc::Samlp2ManageNameIDRequest_issuer_set;
*swig_Extensions_get = *lassoc::Samlp2ManageNameIDRequest_Extensions_get;
*swig_Extensions_set = *lassoc::Samlp2ManageNameIDRequest_Extensions_set;
*swig_ID_get = *lassoc::Samlp2ManageNameIDRequest_ID_get;
*swig_ID_set = *lassoc::Samlp2ManageNameIDRequest_ID_set;
*swig_Version_get = *lassoc::Samlp2ManageNameIDRequest_Version_get;
*swig_Version_set = *lassoc::Samlp2ManageNameIDRequest_Version_set;
*swig_issueInstant_get = *lassoc::Samlp2ManageNameIDRequest_issueInstant_get;
*swig_issueInstant_set = *lassoc::Samlp2ManageNameIDRequest_issueInstant_set;
*swig_Destination_get = *lassoc::Samlp2ManageNameIDRequest_Destination_get;
*swig_Destination_set = *lassoc::Samlp2ManageNameIDRequest_Destination_set;
*swig_Consent_get = *lassoc::Samlp2ManageNameIDRequest_Consent_get;
*swig_Consent_set = *lassoc::Samlp2ManageNameIDRequest_Consent_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2ManageNameIDRequest(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2ManageNameIDRequest($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2ManageNameIDRequest_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Samlp2Scoping ##############

package lasso::Samlp2Scoping;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_RequesterID_get = *lassoc::Samlp2Scoping_RequesterID_get;
*swig_RequesterID_set = *lassoc::Samlp2Scoping_RequesterID_set;
*swig_ProxyCount_get = *lassoc::Samlp2Scoping_ProxyCount_get;
*swig_ProxyCount_set = *lassoc::Samlp2Scoping_ProxyCount_set;
*swig_iDPList_get = *lassoc::Samlp2Scoping_iDPList_get;
*swig_iDPList_set = *lassoc::Samlp2Scoping_iDPList_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Samlp2Scoping(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Samlp2Scoping($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Samlp2Scoping_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : lasso::Saml2Subject ##############

package lasso::Saml2Subject;
use vars qw(@ISA %OWNER %ITERATORS %BLESSEDMEMBERS);
@ISA = qw( lasso );
%OWNER = ();
%ITERATORS = ();
*swig_baseID_get = *lassoc::Saml2Subject_baseID_get;
*swig_baseID_set = *lassoc::Saml2Subject_baseID_set;
*swig_nameID_get = *lassoc::Saml2Subject_nameID_get;
*swig_nameID_set = *lassoc::Saml2Subject_nameID_set;
*swig_encryptedID_get = *lassoc::Saml2Subject_encryptedID_get;
*swig_encryptedID_set = *lassoc::Saml2Subject_encryptedID_set;
*swig_subjectConfirmation_get = *lassoc::Saml2Subject_subjectConfirmation_get;
*swig_subjectConfirmation_set = *lassoc::Saml2Subject_subjectConfirmation_set;
sub new {
    my $pkg = shift;
    my $self = lassoc::new_Saml2Subject(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        lassoc::delete_Saml2Subject($self);
        delete $OWNER{$self};
    }
}

*dump = *lassoc::Saml2Subject_dump;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


# ------- VARIABLE STUBS --------

package lasso;

*WSF_SUPPORT = *lassoc::WSF_SUPPORT;
*SAML2_SUPPORT = *lassoc::SAML2_SUPPORT;
*SAML2_NAME_IDENTIFIER_FORMAT_PERSISTENT = *lassoc::SAML2_NAME_IDENTIFIER_FORMAT_PERSISTENT;
*SAML2_NAME_IDENTIFIER_FORMAT_TRANSIENT = *lassoc::SAML2_NAME_IDENTIFIER_FORMAT_TRANSIENT;
*HTTP_METHOD_NONE = *lassoc::HTTP_METHOD_NONE;
*HTTP_METHOD_ANY = *lassoc::HTTP_METHOD_ANY;
*HTTP_METHOD_IDP_INITIATED = *lassoc::HTTP_METHOD_IDP_INITIATED;
*HTTP_METHOD_GET = *lassoc::HTTP_METHOD_GET;
*HTTP_METHOD_POST = *lassoc::HTTP_METHOD_POST;
*HTTP_METHOD_REDIRECT = *lassoc::HTTP_METHOD_REDIRECT;
*HTTP_METHOD_SOAP = *lassoc::HTTP_METHOD_SOAP;
*HTTP_METHOD_ARTIFACT_GET = *lassoc::HTTP_METHOD_ARTIFACT_GET;
*HTTP_METHOD_ARTIFACT_POST = *lassoc::HTTP_METHOD_ARTIFACT_POST;
*MD_PROTOCOL_TYPE_FEDERATION_TERMINATION = *lassoc::MD_PROTOCOL_TYPE_FEDERATION_TERMINATION;
*MD_PROTOCOL_TYPE_NAME_IDENTIFIER_MAPPING = *lassoc::MD_PROTOCOL_TYPE_NAME_IDENTIFIER_MAPPING;
*MD_PROTOCOL_TYPE_REGISTER_NAME_IDENTIFIER = *lassoc::MD_PROTOCOL_TYPE_REGISTER_NAME_IDENTIFIER;
*MD_PROTOCOL_TYPE_SINGLE_LOGOUT = *lassoc::MD_PROTOCOL_TYPE_SINGLE_LOGOUT;
*MD_PROTOCOL_TYPE_SINGLE_SIGN_ON = *lassoc::MD_PROTOCOL_TYPE_SINGLE_SIGN_ON;
*MD_PROTOCOL_TYPE_ARTIFACT_RESOLUTION = *lassoc::MD_PROTOCOL_TYPE_ARTIFACT_RESOLUTION;
*MD_PROTOCOL_TYPE_MANAGE_NAME_ID = *lassoc::MD_PROTOCOL_TYPE_MANAGE_NAME_ID;
*LASSO_MD_PROTOCOL_TYPE_ASSERTION_ID_REQUEST = *lassoc::LASSO_MD_PROTOCOL_TYPE_ASSERTION_ID_REQUEST;
*LIB_CONSENT_OBTAINED = *lassoc::LIB_CONSENT_OBTAINED;
*LIB_CONSENT_OBTAINED_PRIOR = *lassoc::LIB_CONSENT_OBTAINED_PRIOR;
*LIB_CONSENT_OBTAINED_CURRENT_IMPLICIT = *lassoc::LIB_CONSENT_OBTAINED_CURRENT_IMPLICIT;
*LIB_CONSENT_OBTAINED_CURRENT_EXPLICIT = *lassoc::LIB_CONSENT_OBTAINED_CURRENT_EXPLICIT;
*LIB_CONSENT_UNAVAILABLE = *lassoc::LIB_CONSENT_UNAVAILABLE;
*LIB_CONSENT_INAPPLICABLE = *lassoc::LIB_CONSENT_INAPPLICABLE;
*LIB_NAMEID_POLICY_TYPE_NONE = *lassoc::LIB_NAMEID_POLICY_TYPE_NONE;
*LIB_NAMEID_POLICY_TYPE_ONE_TIME = *lassoc::LIB_NAMEID_POLICY_TYPE_ONE_TIME;
*LIB_NAMEID_POLICY_TYPE_FEDERATED = *lassoc::LIB_NAMEID_POLICY_TYPE_FEDERATED;
*LIB_NAMEID_POLICY_TYPE_ANY = *lassoc::LIB_NAMEID_POLICY_TYPE_ANY;
*LIB_PROTOCOL_PROFILE_BRWS_ART = *lassoc::LIB_PROTOCOL_PROFILE_BRWS_ART;
*LIB_PROTOCOL_PROFILE_BRWS_POST = *lassoc::LIB_PROTOCOL_PROFILE_BRWS_POST;
*LIB_PROTOCOL_PROFILE_BRWS_LECP = *lassoc::LIB_PROTOCOL_PROFILE_BRWS_LECP;
*LIB_PROTOCOL_PROFILE_FED_TERM_IDP_HTTP = *lassoc::LIB_PROTOCOL_PROFILE_FED_TERM_IDP_HTTP;
*LIB_PROTOCOL_PROFILE_FED_TERM_IDP_SOAP = *lassoc::LIB_PROTOCOL_PROFILE_FED_TERM_IDP_SOAP;
*LIB_PROTOCOL_PROFILE_FED_TERM_SP_HTTP = *lassoc::LIB_PROTOCOL_PROFILE_FED_TERM_SP_HTTP;
*LIB_PROTOCOL_PROFILE_FED_TERM_SP_SOAP = *lassoc::LIB_PROTOCOL_PROFILE_FED_TERM_SP_SOAP;
*LIB_PROTOCOL_PROFILE_RNI_IDP_HTTP = *lassoc::LIB_PROTOCOL_PROFILE_RNI_IDP_HTTP;
*LIB_PROTOCOL_PROFILE_RNI_IDP_SOAP = *lassoc::LIB_PROTOCOL_PROFILE_RNI_IDP_SOAP;
*LIB_PROTOCOL_PROFILE_RNI_SP_HTTP = *lassoc::LIB_PROTOCOL_PROFILE_RNI_SP_HTTP;
*LIB_PROTOCOL_PROFILE_RNI_SP_SOAP = *lassoc::LIB_PROTOCOL_PROFILE_RNI_SP_SOAP;
*LIB_PROTOCOL_PROFILE_SLO_IDP_HTTP = *lassoc::LIB_PROTOCOL_PROFILE_SLO_IDP_HTTP;
*LIB_PROTOCOL_PROFILE_SLO_IDP_SOAP = *lassoc::LIB_PROTOCOL_PROFILE_SLO_IDP_SOAP;
*LIB_PROTOCOL_PROFILE_SLO_SP_HTTP = *lassoc::LIB_PROTOCOL_PROFILE_SLO_SP_HTTP;
*LIB_PROTOCOL_PROFILE_SLO_SP_SOAP = *lassoc::LIB_PROTOCOL_PROFILE_SLO_SP_SOAP;
*LOGIN_PROTOCOL_PROFILE_BRWS_ART = *lassoc::LOGIN_PROTOCOL_PROFILE_BRWS_ART;
*LOGIN_PROTOCOL_PROFILE_BRWS_POST = *lassoc::LOGIN_PROTOCOL_PROFILE_BRWS_POST;
*LOGIN_PROTOCOL_PROFILE_BRWS_LECP = *lassoc::LOGIN_PROTOCOL_PROFILE_BRWS_LECP;
*PROVIDER_ROLE_NONE = *lassoc::PROVIDER_ROLE_NONE;
*PROVIDER_ROLE_SP = *lassoc::PROVIDER_ROLE_SP;
*PROVIDER_ROLE_IDP = *lassoc::PROVIDER_ROLE_IDP;
*PROTOCOL_LIBERTY_1_0 = *lassoc::PROTOCOL_LIBERTY_1_0;
*PROTOCOL_LIBERTY_1_1 = *lassoc::PROTOCOL_LIBERTY_1_1;
*PROTOCOL_LIBERTY_1_2 = *lassoc::PROTOCOL_LIBERTY_1_2;
*PROTOCOL_SAML_2_0 = *lassoc::PROTOCOL_SAML_2_0;
*REQUEST_TYPE_INVALID = *lassoc::REQUEST_TYPE_INVALID;
*REQUEST_TYPE_LOGIN = *lassoc::REQUEST_TYPE_LOGIN;
*REQUEST_TYPE_LOGOUT = *lassoc::REQUEST_TYPE_LOGOUT;
*REQUEST_TYPE_DEFEDERATION = *lassoc::REQUEST_TYPE_DEFEDERATION;
*REQUEST_TYPE_NAME_REGISTRATION = *lassoc::REQUEST_TYPE_NAME_REGISTRATION;
*REQUEST_TYPE_NAME_IDENTIFIER_MAPPING = *lassoc::REQUEST_TYPE_NAME_IDENTIFIER_MAPPING;
*REQUEST_TYPE_LECP = *lassoc::REQUEST_TYPE_LECP;
*REQUEST_TYPE_DISCO_QUERY = *lassoc::REQUEST_TYPE_DISCO_QUERY;
*REQUEST_TYPE_DISCO_MODIFY = *lassoc::REQUEST_TYPE_DISCO_MODIFY;
*REQUEST_TYPE_DST_QUERY = *lassoc::REQUEST_TYPE_DST_QUERY;
*REQUEST_TYPE_DST_MODIFY = *lassoc::REQUEST_TYPE_DST_MODIFY;
*REQUEST_TYPE_SASL_REQUEST = *lassoc::REQUEST_TYPE_SASL_REQUEST;
*LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL;
*LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL_PASSWORD = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL_PASSWORD;
*LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_UNREGISTERED = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_UNREGISTERED;
*LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_UNREGISTERED = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_UNREGISTERED;
*LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_CONTRACT = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_CONTRACT;
*LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_CONTRACT = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_CONTRACT;
*LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD;
*LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD_PROTECTED_TRANSPORT = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD_PROTECTED_TRANSPORT;
*LIB_AUTHN_CONTEXT_CLASS_REF_PREVIOUS_SESSION = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_PREVIOUS_SESSION;
*LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD;
*LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD_PKI = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD_PKI;
*LIB_AUTHN_CONTEXT_CLASS_REF_SOFTWARE_PKI = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_SOFTWARE_PKI;
*LIB_AUTHN_CONTEXT_CLASS_REF_TIME_SYNC_TOKEN = *lassoc::LIB_AUTHN_CONTEXT_CLASS_REF_TIME_SYNC_TOKEN;
*LIB_AUTHN_CONTEXT_COMPARISON_EXACT = *lassoc::LIB_AUTHN_CONTEXT_COMPARISON_EXACT;
*LIB_AUTHN_CONTEXT_COMPARISON_MINIMUM = *lassoc::LIB_AUTHN_CONTEXT_COMPARISON_MINIMUM;
*LIB_AUTHN_CONTEXT_COMPARISON_MAXIMUM = *lassoc::LIB_AUTHN_CONTEXT_COMPARISON_MAXIMUM;
*LIB_AUTHN_CONTEXT_COMPARISON_BETTER = *lassoc::LIB_AUTHN_CONTEXT_COMPARISON_BETTER;
*SAML_AUTHENTICATION_METHOD_PASSWORD = *lassoc::SAML_AUTHENTICATION_METHOD_PASSWORD;
*SAML_AUTHENTICATION_METHOD_KERBEROS = *lassoc::SAML_AUTHENTICATION_METHOD_KERBEROS;
*SAML_AUTHENTICATION_METHOD_SECURE_REMOTE_PASSWORD = *lassoc::SAML_AUTHENTICATION_METHOD_SECURE_REMOTE_PASSWORD;
*SAML_AUTHENTICATION_METHOD_HARDWARE_TOKEN = *lassoc::SAML_AUTHENTICATION_METHOD_HARDWARE_TOKEN;
*SAML_AUTHENTICATION_METHOD_SMARTCARD_PKI = *lassoc::SAML_AUTHENTICATION_METHOD_SMARTCARD_PKI;
*SAML_AUTHENTICATION_METHOD_SOFTWARE_PKI = *lassoc::SAML_AUTHENTICATION_METHOD_SOFTWARE_PKI;
*SAML_AUTHENTICATION_METHOD_PGP = *lassoc::SAML_AUTHENTICATION_METHOD_PGP;
*SAML_AUTHENTICATION_METHODS_PKI = *lassoc::SAML_AUTHENTICATION_METHODS_PKI;
*SAML_AUTHENTICATION_METHOD_XKMS = *lassoc::SAML_AUTHENTICATION_METHOD_XKMS;
*SAML_AUTHENTICATION_METHOD_XMLD_SIG = *lassoc::SAML_AUTHENTICATION_METHOD_XMLD_SIG;
*SAML_AUTHENTICATION_METHOD_UNSPECIFIED = *lassoc::SAML_AUTHENTICATION_METHOD_UNSPECIFIED;
*SAML_AUTHENTICATION_METHOD_LIBERTY = *lassoc::SAML_AUTHENTICATION_METHOD_LIBERTY;
*SIGNATURE_METHOD_RSA_SHA1 = *lassoc::SIGNATURE_METHOD_RSA_SHA1;
*SIGNATURE_METHOD_DSA_SHA1 = *lassoc::SIGNATURE_METHOD_DSA_SHA1;
*ERROR_UNDEFINED = *lassoc::ERROR_UNDEFINED;
*ERROR_UNIMPLEMENTED = *lassoc::ERROR_UNIMPLEMENTED;
*XML_ERROR_NODE_NOT_FOUND = *lassoc::XML_ERROR_NODE_NOT_FOUND;
*XML_ERROR_NODE_CONTENT_NOT_FOUND = *lassoc::XML_ERROR_NODE_CONTENT_NOT_FOUND;
*XML_ERROR_ATTR_NOT_FOUND = *lassoc::XML_ERROR_ATTR_NOT_FOUND;
*XML_ERROR_ATTR_VALUE_NOT_FOUND = *lassoc::XML_ERROR_ATTR_VALUE_NOT_FOUND;
*DS_ERROR_SIGNATURE_NOT_FOUND = *lassoc::DS_ERROR_SIGNATURE_NOT_FOUND;
*DS_ERROR_INVALID_SIGNATURE = *lassoc::DS_ERROR_INVALID_SIGNATURE;
*DS_ERROR_SIGNATURE_TMPL_CREATION_FAILED = *lassoc::DS_ERROR_SIGNATURE_TMPL_CREATION_FAILED;
*DS_ERROR_CONTEXT_CREATION_FAILED = *lassoc::DS_ERROR_CONTEXT_CREATION_FAILED;
*DS_ERROR_PUBLIC_KEY_LOAD_FAILED = *lassoc::DS_ERROR_PUBLIC_KEY_LOAD_FAILED;
*DS_ERROR_PRIVATE_KEY_LOAD_FAILED = *lassoc::DS_ERROR_PRIVATE_KEY_LOAD_FAILED;
*DS_ERROR_CERTIFICATE_LOAD_FAILED = *lassoc::DS_ERROR_CERTIFICATE_LOAD_FAILED;
*DS_ERROR_SIGNATURE_FAILED = *lassoc::DS_ERROR_SIGNATURE_FAILED;
*DS_ERROR_KEYS_MNGR_CREATION_FAILED = *lassoc::DS_ERROR_KEYS_MNGR_CREATION_FAILED;
*DS_ERROR_KEYS_MNGR_INIT_FAILED = *lassoc::DS_ERROR_KEYS_MNGR_INIT_FAILED;
*DS_ERROR_SIGNATURE_VERIFICATION_FAILED = *lassoc::DS_ERROR_SIGNATURE_VERIFICATION_FAILED;
*DS_ERROR_CA_CERT_CHAIN_LOAD_FAILED = *lassoc::DS_ERROR_CA_CERT_CHAIN_LOAD_FAILED;
*DS_ERROR_INVALID_SIGALG = *lassoc::DS_ERROR_INVALID_SIGALG;
*DS_ERROR_DIGEST_COMPUTE_FAILED = *lassoc::DS_ERROR_DIGEST_COMPUTE_FAILED;
*LASSO_DS_ERROR_SIGNATURE_TEMPLATE_NOT_FOUND = *lassoc::LASSO_DS_ERROR_SIGNATURE_TEMPLATE_NOT_FOUND;
*SERVER_ERROR_PROVIDER_NOT_FOUND = *lassoc::SERVER_ERROR_PROVIDER_NOT_FOUND;
*SERVER_ERROR_ADD_PROVIDER_FAILED = *lassoc::SERVER_ERROR_ADD_PROVIDER_FAILED;
*LASSO_SERVER_ERROR_ADD_PROVIDER_PROTOCOL_MISMATCH = *lassoc::LASSO_SERVER_ERROR_ADD_PROVIDER_PROTOCOL_MISMATCH;
*LOGOUT_ERROR_UNSUPPORTED_PROFILE = *lassoc::LOGOUT_ERROR_UNSUPPORTED_PROFILE;
*LOGOUT_ERROR_REQUEST_DENIED = *lassoc::LOGOUT_ERROR_REQUEST_DENIED;
*PROFILE_ERROR_INVALID_QUERY = *lassoc::PROFILE_ERROR_INVALID_QUERY;
*PROFILE_ERROR_INVALID_POST_MSG = *lassoc::PROFILE_ERROR_INVALID_POST_MSG;
*PROFILE_ERROR_INVALID_SOAP_MSG = *lassoc::PROFILE_ERROR_INVALID_SOAP_MSG;
*PROFILE_ERROR_MISSING_REQUEST = *lassoc::PROFILE_ERROR_MISSING_REQUEST;
*PROFILE_ERROR_INVALID_HTTP_METHOD = *lassoc::PROFILE_ERROR_INVALID_HTTP_METHOD;
*PROFILE_ERROR_INVALID_PROTOCOLPROFILE = *lassoc::PROFILE_ERROR_INVALID_PROTOCOLPROFILE;
*PROFILE_ERROR_INVALID_MSG = *lassoc::PROFILE_ERROR_INVALID_MSG;
*PROFILE_ERROR_MISSING_REMOTE_PROVIDERID = *lassoc::PROFILE_ERROR_MISSING_REMOTE_PROVIDERID;
*PROFILE_ERROR_UNSUPPORTED_PROFILE = *lassoc::PROFILE_ERROR_UNSUPPORTED_PROFILE;
*PROFILE_ERROR_UNKNOWN_PROFILE_URL = *lassoc::PROFILE_ERROR_UNKNOWN_PROFILE_URL;
*PROFILE_ERROR_IDENTITY_NOT_FOUND = *lassoc::PROFILE_ERROR_IDENTITY_NOT_FOUND;
*PROFILE_ERROR_FEDERATION_NOT_FOUND = *lassoc::PROFILE_ERROR_FEDERATION_NOT_FOUND;
*PROFILE_ERROR_NAME_IDENTIFIER_NOT_FOUND = *lassoc::PROFILE_ERROR_NAME_IDENTIFIER_NOT_FOUND;
*PROFILE_ERROR_BUILDING_QUERY_FAILED = *lassoc::PROFILE_ERROR_BUILDING_QUERY_FAILED;
*PROFILE_ERROR_BUILDING_REQUEST_FAILED = *lassoc::PROFILE_ERROR_BUILDING_REQUEST_FAILED;
*PROFILE_ERROR_BUILDING_MESSAGE_FAILED = *lassoc::PROFILE_ERROR_BUILDING_MESSAGE_FAILED;
*PROFILE_ERROR_BUILDING_RESPONSE_FAILED = *lassoc::PROFILE_ERROR_BUILDING_RESPONSE_FAILED;
*PROFILE_ERROR_SESSION_NOT_FOUND = *lassoc::PROFILE_ERROR_SESSION_NOT_FOUND;
*PROFILE_ERROR_BAD_IDENTITY_DUMP = *lassoc::PROFILE_ERROR_BAD_IDENTITY_DUMP;
*PROFILE_ERROR_BAD_SESSION_DUMP = *lassoc::PROFILE_ERROR_BAD_SESSION_DUMP;
*LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ = *lassoc::LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ;
*PARAM_ERROR_INVALID_VALUE = *lassoc::PARAM_ERROR_INVALID_VALUE;
*LASSO_PARAM_ERROR_CHECK_FAILED = *lassoc::LASSO_PARAM_ERROR_CHECK_FAILED;
*LOGIN_ERROR_FEDERATION_NOT_FOUND = *lassoc::LOGIN_ERROR_FEDERATION_NOT_FOUND;
*LOGIN_ERROR_CONSENT_NOT_OBTAINED = *lassoc::LOGIN_ERROR_CONSENT_NOT_OBTAINED;
*LOGIN_ERROR_INVALID_NAMEIDPOLICY = *lassoc::LOGIN_ERROR_INVALID_NAMEIDPOLICY;
*LOGIN_ERROR_REQUEST_DENIED = *lassoc::LOGIN_ERROR_REQUEST_DENIED;
*LOGIN_ERROR_INVALID_SIGNATURE = *lassoc::LOGIN_ERROR_INVALID_SIGNATURE;
*LOGIN_ERROR_UNSIGNED_AUTHN_REQUEST = *lassoc::LOGIN_ERROR_UNSIGNED_AUTHN_REQUEST;
*LOGIN_ERROR_STATUS_NOT_SUCCESS = *lassoc::LOGIN_ERROR_STATUS_NOT_SUCCESS;
*LOGIN_ERROR_UNKNOWN_PRINCIPAL = *lassoc::LOGIN_ERROR_UNKNOWN_PRINCIPAL;
*DEFEDERATION_ERROR_MISSING_NAME_IDENTIFIER = *lassoc::DEFEDERATION_ERROR_MISSING_NAME_IDENTIFIER;
*LASSO_SOAP_FAULT_REDIRECT_REQUEST = *lassoc::LASSO_SOAP_FAULT_REDIRECT_REQUEST;
*CHECK_VERSION_EXACT = *lassoc::CHECK_VERSION_EXACT;
*CHECK_VERSIONABI_COMPATIBLE = *lassoc::CHECK_VERSIONABI_COMPATIBLE;
*CHECK_VERSION_NUMERIC = *lassoc::CHECK_VERSION_NUMERIC;
1;
