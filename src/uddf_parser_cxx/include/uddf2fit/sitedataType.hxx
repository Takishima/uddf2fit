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

#ifndef SITEDATA_TYPE_HXX
#define SITEDATA_TYPE_HXX

#include "sitedataType-fwd.hxx"

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

#include "ratingvalueType-fwd.hxx"

#include "globallightintensityType-fwd.hxx"

#include "wreckType-fwd.hxx"

#include "caveType-fwd.hxx"

#include "indoorType-fwd.hxx"

#include "placeType-fwd.hxx"

namespace streit
{
  class sitedataType: public ::xml_schema::type
  {
    public:
    // arealength
    //
    typedef ::xml_schema::float_ arealength_type;
    typedef ::xsd::cxx::tree::optional< arealength_type > arealength_optional;
    typedef ::xsd::cxx::tree::traits< arealength_type, char > arealength_traits;

    const arealength_optional&
    arealength () const;

    arealength_optional&
    arealength ();

    void
    arealength (const arealength_type& x);

    void
    arealength (const arealength_optional& x);

    // areawidth
    //
    typedef ::xml_schema::float_ areawidth_type;
    typedef ::xsd::cxx::tree::optional< areawidth_type > areawidth_optional;
    typedef ::xsd::cxx::tree::traits< areawidth_type, char > areawidth_traits;

    const areawidth_optional&
    areawidth () const;

    areawidth_optional&
    areawidth ();

    void
    areawidth (const areawidth_type& x);

    void
    areawidth (const areawidth_optional& x);

    // averagevisibility
    //
    typedef ::xml_schema::float_ averagevisibility_type;
    typedef ::xsd::cxx::tree::optional< averagevisibility_type > averagevisibility_optional;
    typedef ::xsd::cxx::tree::traits< averagevisibility_type, char > averagevisibility_traits;

    const averagevisibility_optional&
    averagevisibility () const;

    averagevisibility_optional&
    averagevisibility ();

    void
    averagevisibility (const averagevisibility_type& x);

    void
    averagevisibility (const averagevisibility_optional& x);

    // bottom
    //
    typedef ::xml_schema::string bottom_type;
    typedef ::xsd::cxx::tree::optional< bottom_type > bottom_optional;
    typedef ::xsd::cxx::tree::traits< bottom_type, char > bottom_traits;

    const bottom_optional&
    bottom () const;

    bottom_optional&
    bottom ();

    void
    bottom (const bottom_type& x);

    void
    bottom (const bottom_optional& x);

    void
    bottom (::std::unique_ptr< bottom_type > p);

    // density
    //
    typedef ::xml_schema::float_ density_type;
    typedef ::xsd::cxx::tree::optional< density_type > density_optional;
    typedef ::xsd::cxx::tree::traits< density_type, char > density_traits;

    const density_optional&
    density () const;

    density_optional&
    density ();

    void
    density (const density_type& x);

    void
    density (const density_optional& x);

    // difficulty
    //
    typedef ::streit::ratingvalueType difficulty_type;
    typedef ::xsd::cxx::tree::optional< difficulty_type > difficulty_optional;
    typedef ::xsd::cxx::tree::traits< difficulty_type, char > difficulty_traits;

    const difficulty_optional&
    difficulty () const;

    difficulty_optional&
    difficulty ();

    void
    difficulty (const difficulty_type& x);

    void
    difficulty (const difficulty_optional& x);

    void
    difficulty (::std::unique_ptr< difficulty_type > p);

    // globallightintensity
    //
    typedef ::streit::globallightintensityType globallightintensity_type;
    typedef ::xsd::cxx::tree::optional< globallightintensity_type > globallightintensity_optional;
    typedef ::xsd::cxx::tree::traits< globallightintensity_type, char > globallightintensity_traits;

    const globallightintensity_optional&
    globallightintensity () const;

    globallightintensity_optional&
    globallightintensity ();

    void
    globallightintensity (const globallightintensity_type& x);

    void
    globallightintensity (const globallightintensity_optional& x);

    void
    globallightintensity (::std::unique_ptr< globallightintensity_type > p);

    // maximumdepth
    //
    typedef ::xml_schema::float_ maximumdepth_type;
    typedef ::xsd::cxx::tree::optional< maximumdepth_type > maximumdepth_optional;
    typedef ::xsd::cxx::tree::traits< maximumdepth_type, char > maximumdepth_traits;

    const maximumdepth_optional&
    maximumdepth () const;

    maximumdepth_optional&
    maximumdepth ();

    void
    maximumdepth (const maximumdepth_type& x);

    void
    maximumdepth (const maximumdepth_optional& x);

    // maximumvisibility
    //
    typedef ::xml_schema::float_ maximumvisibility_type;
    typedef ::xsd::cxx::tree::optional< maximumvisibility_type > maximumvisibility_optional;
    typedef ::xsd::cxx::tree::traits< maximumvisibility_type, char > maximumvisibility_traits;

    const maximumvisibility_optional&
    maximumvisibility () const;

    maximumvisibility_optional&
    maximumvisibility ();

    void
    maximumvisibility (const maximumvisibility_type& x);

    void
    maximumvisibility (const maximumvisibility_optional& x);

    // minimumdepth
    //
    typedef ::xml_schema::float_ minimumdepth_type;
    typedef ::xsd::cxx::tree::optional< minimumdepth_type > minimumdepth_optional;
    typedef ::xsd::cxx::tree::traits< minimumdepth_type, char > minimumdepth_traits;

    const minimumdepth_optional&
    minimumdepth () const;

    minimumdepth_optional&
    minimumdepth ();

    void
    minimumdepth (const minimumdepth_type& x);

    void
    minimumdepth (const minimumdepth_optional& x);

    // minimumvisibility
    //
    typedef ::xml_schema::float_ minimumvisibility_type;
    typedef ::xsd::cxx::tree::optional< minimumvisibility_type > minimumvisibility_optional;
    typedef ::xsd::cxx::tree::traits< minimumvisibility_type, char > minimumvisibility_traits;

    const minimumvisibility_optional&
    minimumvisibility () const;

    minimumvisibility_optional&
    minimumvisibility ();

    void
    minimumvisibility (const minimumvisibility_type& x);

    void
    minimumvisibility (const minimumvisibility_optional& x);

    // terrain
    //
    typedef ::xml_schema::string terrain_type;
    typedef ::xsd::cxx::tree::optional< terrain_type > terrain_optional;
    typedef ::xsd::cxx::tree::traits< terrain_type, char > terrain_traits;

    const terrain_optional&
    terrain () const;

    terrain_optional&
    terrain ();

    void
    terrain (const terrain_type& x);

    void
    terrain (const terrain_optional& x);

    void
    terrain (::std::unique_ptr< terrain_type > p);

    // wreck
    //
    typedef ::streit::wreckType wreck_type;
    typedef ::xsd::cxx::tree::sequence< wreck_type > wreck_sequence;
    typedef wreck_sequence::iterator wreck_iterator;
    typedef wreck_sequence::const_iterator wreck_const_iterator;
    typedef ::xsd::cxx::tree::traits< wreck_type, char > wreck_traits;

    const wreck_sequence&
    wreck () const;

    wreck_sequence&
    wreck ();

    void
    wreck (const wreck_sequence& s);

    // cave
    //
    typedef ::streit::caveType cave_type;
    typedef ::xsd::cxx::tree::optional< cave_type > cave_optional;
    typedef ::xsd::cxx::tree::traits< cave_type, char > cave_traits;

    const cave_optional&
    cave () const;

    cave_optional&
    cave ();

    void
    cave (const cave_type& x);

    void
    cave (const cave_optional& x);

    void
    cave (::std::unique_ptr< cave_type > p);

    // indoor
    //
    typedef ::streit::indoorType indoor_type;
    typedef ::xsd::cxx::tree::optional< indoor_type > indoor_optional;
    typedef ::xsd::cxx::tree::traits< indoor_type, char > indoor_traits;

    const indoor_optional&
    indoor () const;

    indoor_optional&
    indoor ();

    void
    indoor (const indoor_type& x);

    void
    indoor (const indoor_optional& x);

    void
    indoor (::std::unique_ptr< indoor_type > p);

    // lake
    //
    typedef ::streit::placeType lake_type;
    typedef ::xsd::cxx::tree::optional< lake_type > lake_optional;
    typedef ::xsd::cxx::tree::traits< lake_type, char > lake_traits;

    const lake_optional&
    lake () const;

    lake_optional&
    lake ();

    void
    lake (const lake_type& x);

    void
    lake (const lake_optional& x);

    void
    lake (::std::unique_ptr< lake_type > p);

    // river
    //
    typedef ::streit::placeType river_type;
    typedef ::xsd::cxx::tree::optional< river_type > river_optional;
    typedef ::xsd::cxx::tree::traits< river_type, char > river_traits;

    const river_optional&
    river () const;

    river_optional&
    river ();

    void
    river (const river_type& x);

    void
    river (const river_optional& x);

    void
    river (::std::unique_ptr< river_type > p);

    // shore
    //
    typedef ::streit::placeType shore_type;
    typedef ::xsd::cxx::tree::optional< shore_type > shore_optional;
    typedef ::xsd::cxx::tree::traits< shore_type, char > shore_traits;

    const shore_optional&
    shore () const;

    shore_optional&
    shore ();

    void
    shore (const shore_type& x);

    void
    shore (const shore_optional& x);

    void
    shore (::std::unique_ptr< shore_type > p);

    // Constructors.
    //
    sitedataType ();

    sitedataType (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    sitedataType (const sitedataType& x,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    virtual sitedataType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    sitedataType&
    operator= (const sitedataType& x);

    virtual 
    ~sitedataType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    arealength_optional arealength_;
    areawidth_optional areawidth_;
    averagevisibility_optional averagevisibility_;
    bottom_optional bottom_;
    density_optional density_;
    difficulty_optional difficulty_;
    globallightintensity_optional globallightintensity_;
    maximumdepth_optional maximumdepth_;
    maximumvisibility_optional maximumvisibility_;
    minimumdepth_optional minimumdepth_;
    minimumvisibility_optional minimumvisibility_;
    terrain_optional terrain_;
    wreck_sequence wreck_;
    cave_optional cave_;
    indoor_optional indoor_;
    lake_optional lake_;
    river_optional river_;
    shore_optional shore_;
  };
}

#include <iosfwd>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream&, const sitedataType&);
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

#endif // SITEDATA_TYPE_HXX
