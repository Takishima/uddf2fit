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

#include "generator.hxx"

#include "type.hxx"

#include "linkType.hxx"

#include "manufacturerType.hxx"

namespace streit
{
  // generator
  //

  const generator::type_optional& generator::
  type () const
  {
    return this->type_;
  }

  generator::type_optional& generator::
  type ()
  {
    return this->type_;
  }

  void generator::
  type (const type_type& x)
  {
    this->type_.set (x);
  }

  void generator::
  type (const type_optional& x)
  {
    this->type_ = x;
  }

  void generator::
  type (::std::unique_ptr< type_type > x)
  {
    this->type_.set (std::move (x));
  }

  const generator::link_optional& generator::
  link () const
  {
    return this->link_;
  }

  generator::link_optional& generator::
  link ()
  {
    return this->link_;
  }

  void generator::
  link (const link_type& x)
  {
    this->link_.set (x);
  }

  void generator::
  link (const link_optional& x)
  {
    this->link_ = x;
  }

  void generator::
  link (::std::unique_ptr< link_type > x)
  {
    this->link_.set (std::move (x));
  }

  const generator::manufacturer_optional& generator::
  manufacturer () const
  {
    return this->manufacturer_;
  }

  generator::manufacturer_optional& generator::
  manufacturer ()
  {
    return this->manufacturer_;
  }

  void generator::
  manufacturer (const manufacturer_type& x)
  {
    this->manufacturer_.set (x);
  }

  void generator::
  manufacturer (const manufacturer_optional& x)
  {
    this->manufacturer_ = x;
  }

  void generator::
  manufacturer (::std::unique_ptr< manufacturer_type > x)
  {
    this->manufacturer_.set (std::move (x));
  }

  const generator::version_optional& generator::
  version () const
  {
    return this->version_;
  }

  generator::version_optional& generator::
  version ()
  {
    return this->version_;
  }

  void generator::
  version (const version_type& x)
  {
    this->version_.set (x);
  }

  void generator::
  version (const version_optional& x)
  {
    this->version_ = x;
  }

  void generator::
  version (::std::unique_ptr< version_type > x)
  {
    this->version_.set (std::move (x));
  }

  const generator::datetime_optional& generator::
  datetime () const
  {
    return this->datetime_;
  }

  generator::datetime_optional& generator::
  datetime ()
  {
    return this->datetime_;
  }

  void generator::
  datetime (const datetime_type& x)
  {
    this->datetime_.set (x);
  }

  void generator::
  datetime (const datetime_optional& x)
  {
    this->datetime_ = x;
  }

  void generator::
  datetime (::std::unique_ptr< datetime_type > x)
  {
    this->datetime_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // generator
  //

  generator::
  generator (const name_type& name)
  : ::streit::simpleNamedType (name),
    type_ (this),
    link_ (this),
    manufacturer_ (this),
    version_ (this),
    datetime_ (this)
  {
  }

  generator::
  generator (const generator& x,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::streit::simpleNamedType (x, f, c),
    type_ (x.type_, f, this),
    link_ (x.link_, f, this),
    manufacturer_ (x.manufacturer_, f, this),
    version_ (x.version_, f, this),
    datetime_ (x.datetime_, f, this)
  {
  }

  generator::
  generator (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::streit::simpleNamedType (e, f | ::xml_schema::flags::base, c),
    type_ (this),
    link_ (this),
    manufacturer_ (this),
    version_ (this),
    datetime_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void generator::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    this->::streit::simpleNamedType::parse (p, f);

    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // type
      //
      if (n.name () == "type" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< type_type > r (
          type_traits::create (i, f, this));

        if (!this->type_)
        {
          this->type_.set (::std::move (r));
          continue;
        }
      }

      // link
      //
      if (n.name () == "link" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< link_type > r (
          link_traits::create (i, f, this));

        if (!this->link_)
        {
          this->link_.set (::std::move (r));
          continue;
        }
      }

      // manufacturer
      //
      if (n.name () == "manufacturer" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< manufacturer_type > r (
          manufacturer_traits::create (i, f, this));

        if (!this->manufacturer_)
        {
          this->manufacturer_.set (::std::move (r));
          continue;
        }
      }

      // version
      //
      if (n.name () == "version" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< version_type > r (
          version_traits::create (i, f, this));

        if (!this->version_)
        {
          this->version_.set (::std::move (r));
          continue;
        }
      }

      // datetime
      //
      if (n.name () == "datetime" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< datetime_type > r (
          datetime_traits::create (i, f, this));

        if (!this->datetime_)
        {
          this->datetime_.set (::std::move (r));
          continue;
        }
      }

      break;
    }
  }

  generator* generator::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class generator (*this, f, c);
  }

  generator& generator::
  operator= (const generator& x)
  {
    if (this != &x)
    {
      static_cast< ::streit::simpleNamedType& > (*this) = x;
      this->type_ = x.type_;
      this->link_ = x.link_;
      this->manufacturer_ = x.manufacturer_;
      this->version_ = x.version_;
      this->datetime_ = x.datetime_;
    }

    return *this;
  }

  generator::
  ~generator ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const generator& i)
  {
    o << static_cast< const ::streit::simpleNamedType& > (i);

    if (i.type ())
    {
      o << ::std::endl << "type: " << *i.type ();
    }

    if (i.link ())
    {
      o << ::std::endl << "link: " << *i.link ();
    }

    if (i.manufacturer ())
    {
      o << ::std::endl << "manufacturer: " << *i.manufacturer ();
    }

    if (i.version ())
    {
      o << ::std::endl << "version: " << *i.version ();
    }

    if (i.datetime ())
    {
      o << ::std::endl << "datetime: " << *i.datetime ();
    }

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

