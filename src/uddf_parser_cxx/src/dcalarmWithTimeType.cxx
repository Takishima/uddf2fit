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

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "dcalarmWithTimeType.hxx"

#include "dcalarmType.hxx"

namespace streit
{
  // dcalarmWithTimeType
  //

  const dcalarmWithTimeType::dcalarm_type& dcalarmWithTimeType::
  dcalarm () const
  {
    return this->dcalarm_.get ();
  }

  dcalarmWithTimeType::dcalarm_type& dcalarmWithTimeType::
  dcalarm ()
  {
    return this->dcalarm_.get ();
  }

  void dcalarmWithTimeType::
  dcalarm (const dcalarm_type& x)
  {
    this->dcalarm_.set (x);
  }

  void dcalarmWithTimeType::
  dcalarm (::std::unique_ptr< dcalarm_type > x)
  {
    this->dcalarm_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // dcalarmWithTimeType
  //

  dcalarmWithTimeType::
  dcalarmWithTimeType (const datetime_type& datetime,
                       const dcalarm_type& dcalarm)
  : ::streit::encapsulatedDateTimeType (datetime),
    dcalarm_ (dcalarm, this)
  {
  }

  dcalarmWithTimeType::
  dcalarmWithTimeType (const datetime_type& datetime,
                       ::std::unique_ptr< dcalarm_type > dcalarm)
  : ::streit::encapsulatedDateTimeType (datetime),
    dcalarm_ (std::move (dcalarm), this)
  {
  }

  dcalarmWithTimeType::
  dcalarmWithTimeType (const dcalarmWithTimeType& x,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::streit::encapsulatedDateTimeType (x, f, c),
    dcalarm_ (x.dcalarm_, f, this)
  {
  }

  dcalarmWithTimeType::
  dcalarmWithTimeType (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::streit::encapsulatedDateTimeType (e, f | ::xml_schema::flags::base, c),
    dcalarm_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void dcalarmWithTimeType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    this->::streit::encapsulatedDateTimeType::parse (p, f);

    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // dcalarm
      //
      if (n.name () == "dcalarm" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< dcalarm_type > r (
          dcalarm_traits::create (i, f, this));

        if (!dcalarm_.present ())
        {
          this->dcalarm_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!dcalarm_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "dcalarm",
        "http://www.streit.cc/uddf/3.2/");
    }
  }

  dcalarmWithTimeType* dcalarmWithTimeType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class dcalarmWithTimeType (*this, f, c);
  }

  dcalarmWithTimeType& dcalarmWithTimeType::
  operator= (const dcalarmWithTimeType& x)
  {
    if (this != &x)
    {
      static_cast< ::streit::encapsulatedDateTimeType& > (*this) = x;
      this->dcalarm_ = x.dcalarm_;
    }

    return *this;
  }

  dcalarmWithTimeType::
  ~dcalarmWithTimeType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const dcalarmWithTimeType& i)
  {
    o << static_cast< const ::streit::encapsulatedDateTimeType& > (i);

    o << ::std::endl << "dcalarm: " << i.dcalarm ();
    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

