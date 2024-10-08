// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

#ifndef BOTTOMTIMETABLESCOPE_TYPE_HXX
#define BOTTOMTIMETABLESCOPE_TYPE_HXX

#include "bottomtimetablescopeType-fwd.hxx"

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (LIBXSD_VERSION != 400002000000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

namespace streit
{
  class bottomtimetablescopeType: public ::xml_schema::type
  {
    public:
    // divedepthbegin
    //
    typedef ::xml_schema::float_ divedepthbegin_type;
    typedef ::xsd::cxx::tree::traits< divedepthbegin_type, char > divedepthbegin_traits;

    const divedepthbegin_type&
    divedepthbegin () const;

    divedepthbegin_type&
    divedepthbegin ();

    void
    divedepthbegin (const divedepthbegin_type& x);

    // divedepthend
    //
    typedef ::xml_schema::float_ divedepthend_type;
    typedef ::xsd::cxx::tree::traits< divedepthend_type, char > divedepthend_traits;

    const divedepthend_type&
    divedepthend () const;

    divedepthend_type&
    divedepthend ();

    void
    divedepthend (const divedepthend_type& x);

    // divedepthstep
    //
    typedef ::xml_schema::float_ divedepthstep_type;
    typedef ::xsd::cxx::tree::traits< divedepthstep_type, char > divedepthstep_traits;

    const divedepthstep_type&
    divedepthstep () const;

    divedepthstep_type&
    divedepthstep ();

    void
    divedepthstep (const divedepthstep_type& x);

    // breathingconsumptionvolumebegin
    //
    typedef ::xml_schema::float_ breathingconsumptionvolumebegin_type;
    typedef ::xsd::cxx::tree::traits< breathingconsumptionvolumebegin_type, char > breathingconsumptionvolumebegin_traits;

    const breathingconsumptionvolumebegin_type&
    breathingconsumptionvolumebegin () const;

    breathingconsumptionvolumebegin_type&
    breathingconsumptionvolumebegin ();

    void
    breathingconsumptionvolumebegin (const breathingconsumptionvolumebegin_type& x);

    // breathingconsumptionvolumeend
    //
    typedef ::xml_schema::float_ breathingconsumptionvolumeend_type;
    typedef ::xsd::cxx::tree::traits< breathingconsumptionvolumeend_type, char > breathingconsumptionvolumeend_traits;

    const breathingconsumptionvolumeend_type&
    breathingconsumptionvolumeend () const;

    breathingconsumptionvolumeend_type&
    breathingconsumptionvolumeend ();

    void
    breathingconsumptionvolumeend (const breathingconsumptionvolumeend_type& x);

    // breathingconsumptionvolumestep
    //
    typedef ::xml_schema::float_ breathingconsumptionvolumestep_type;
    typedef ::xsd::cxx::tree::traits< breathingconsumptionvolumestep_type, char > breathingconsumptionvolumestep_traits;

    const breathingconsumptionvolumestep_type&
    breathingconsumptionvolumestep () const;

    breathingconsumptionvolumestep_type&
    breathingconsumptionvolumestep ();

    void
    breathingconsumptionvolumestep (const breathingconsumptionvolumestep_type& x);

    // tankvolumebegin
    //
    typedef ::xml_schema::float_ tankvolumebegin_type;
    typedef ::xsd::cxx::tree::traits< tankvolumebegin_type, char > tankvolumebegin_traits;

    const tankvolumebegin_type&
    tankvolumebegin () const;

    tankvolumebegin_type&
    tankvolumebegin ();

    void
    tankvolumebegin (const tankvolumebegin_type& x);

    // tankvolumeend
    //
    typedef ::xml_schema::float_ tankvolumeend_type;
    typedef ::xsd::cxx::tree::traits< tankvolumeend_type, char > tankvolumeend_traits;

    const tankvolumeend_type&
    tankvolumeend () const;

    tankvolumeend_type&
    tankvolumeend ();

    void
    tankvolumeend (const tankvolumeend_type& x);

    // tankvolumestep
    //
    typedef ::xml_schema::float_ tankvolumestep_type;
    typedef ::xsd::cxx::tree::traits< tankvolumestep_type, char > tankvolumestep_traits;

    const tankvolumestep_type&
    tankvolumestep () const;

    tankvolumestep_type&
    tankvolumestep ();

    void
    tankvolumestep (const tankvolumestep_type& x);

    // tankpressurebegin
    //
    typedef ::xml_schema::float_ tankpressurebegin_type;
    typedef ::xsd::cxx::tree::traits< tankpressurebegin_type, char > tankpressurebegin_traits;

    const tankpressurebegin_type&
    tankpressurebegin () const;

    tankpressurebegin_type&
    tankpressurebegin ();

    void
    tankpressurebegin (const tankpressurebegin_type& x);

    // tankpressurereserve
    //
    typedef ::xml_schema::float_ tankpressurereserve_type;
    typedef ::xsd::cxx::tree::traits< tankpressurereserve_type, char > tankpressurereserve_traits;

    const tankpressurereserve_type&
    tankpressurereserve () const;

    tankpressurereserve_type&
    tankpressurereserve ();

    void
    tankpressurereserve (const tankpressurereserve_type& x);

    // Constructors.
    //
    bottomtimetablescopeType (const divedepthbegin_type&,
                              const divedepthend_type&,
                              const divedepthstep_type&,
                              const breathingconsumptionvolumebegin_type&,
                              const breathingconsumptionvolumeend_type&,
                              const breathingconsumptionvolumestep_type&,
                              const tankvolumebegin_type&,
                              const tankvolumeend_type&,
                              const tankvolumestep_type&,
                              const tankpressurebegin_type&,
                              const tankpressurereserve_type&);

    bottomtimetablescopeType (const ::xercesc::DOMElement& e,
                              ::xml_schema::flags f = 0,
                              ::xml_schema::container* c = 0);

    bottomtimetablescopeType (const bottomtimetablescopeType& x,
                              ::xml_schema::flags f = 0,
                              ::xml_schema::container* c = 0);

    virtual bottomtimetablescopeType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    bottomtimetablescopeType&
    operator= (const bottomtimetablescopeType& x);

    virtual 
    ~bottomtimetablescopeType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< divedepthbegin_type > divedepthbegin_;
    ::xsd::cxx::tree::one< divedepthend_type > divedepthend_;
    ::xsd::cxx::tree::one< divedepthstep_type > divedepthstep_;
    ::xsd::cxx::tree::one< breathingconsumptionvolumebegin_type > breathingconsumptionvolumebegin_;
    ::xsd::cxx::tree::one< breathingconsumptionvolumeend_type > breathingconsumptionvolumeend_;
    ::xsd::cxx::tree::one< breathingconsumptionvolumestep_type > breathingconsumptionvolumestep_;
    ::xsd::cxx::tree::one< tankvolumebegin_type > tankvolumebegin_;
    ::xsd::cxx::tree::one< tankvolumeend_type > tankvolumeend_;
    ::xsd::cxx::tree::one< tankvolumestep_type > tankvolumestep_;
    ::xsd::cxx::tree::one< tankpressurebegin_type > tankpressurebegin_;
    ::xsd::cxx::tree::one< tankpressurereserve_type > tankpressurereserve_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const bottomtimetablescopeType&);
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // BOTTOMTIMETABLESCOPE_TYPE_HXX
